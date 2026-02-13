/**
 * @file Client.cpp
 * @brief Implements the Client class representing an ECSBF endpoint node.
 *
 * This file contains the runtime behavior of a client node within the
 * Enterprise Concurrent Signal Broadcast Framework (ECSBF).
 *
 * Responsibilities:
 * - Establish TCP connection with ECSBF Core Engine (FR-01)
 * - Support node registration (FR-02)
 * - Perform login authentication (FR-03)
 * - Maintain encrypted session communication (FR-10, FR-11)
 * - Support persistent listening for broadcast messages (FR-04)
 * - Log operational events (FR-12)
 *
 * The client operates in a loop-driven interactive model,
 * supporting secure chat-style broadcast communication.
 */

#include <Client.h>
#include <NetworkUtil.h>
#include <Logger.h>

#include <iostream>
#include <thread>
#include <atomic>
#include <unistd.h>
#include <arpa/inet.h>
#include <CryptoUtil.h>

/**
 * @brief Global atomic flag controlling client runtime state.
 *
 * Ensures thread-safe coordination between:
 * - Main input loop
 * - Background message receiver thread
 */
static std::atomic<bool> running(true);

/**
 * @brief Constructs a Client instance.
 *
 * Initializes networking parameters and sets
 * the initial socket descriptor to invalid state.
 */
Client::Client(const std::string& ip, int port)
    : sock(-1), serverIp(ip), serverPort(port) {}


/**
 * @brief Continuously listens for incoming broadcast messages.
 *
 * This method:
 * - Receives encrypted packets from the Engine
 * - Decrypts payload using session key
 * - Displays decrypted message to console
 *
 * Runs in a dedicated background thread to enable
 * simultaneous sending and receiving of messages.
 */
void Client::listenForMessages() {
    try {
        while (running) {

            // Receive encrypted broadcast packet
            std::string msg = NetworkUtil::receivePacket(sock);

            // Exit condition: shutdown or empty packet
            if (!running || msg.empty())
                break;

            // Decrypt received payload using session key (FR-11)
            std::string decrypted =
                CryptoUtil::decrypt(msg, sessionKey);

            // Display decrypted broadcast message
            std::cout << decrypted << std::endl;
        }
    }
    catch (const std::exception& e) {

        // Log runtime receive errors (FR-12 Observability)
        Logger::getInstance().log("client.log", INFO,
            std::string("Client receive error: ") + e.what()
        );
    }
}


/**
 * @brief Establishes connection and manages client interaction lifecycle.
 *
 * Workflow:
 * 1. Establish TCP connection to Engine (FR-01)
 * 2. Provide registration or login option (FR-02, FR-03)
 * 3. On successful login:
 *    - Extract session key
 *    - Enable encrypted chat communication (FR-10, FR-11)
 * 4. Spawn background receiver thread (FR-04)
 * 5. Support controlled shutdown
 */
void Client::connectToEngine() {

    while (true) {

        /*
         * ----------------------------------------------------
         *  Create TCP socket and connect to Engine
         * ----------------------------------------------------
         */
        sock = socket(AF_INET, SOCK_STREAM, 0);

        sockaddr_in addr{};
        addr.sin_family = AF_INET;
        addr.sin_port = htons(serverPort);
        inet_pton(AF_INET, serverIp.c_str(), &addr.sin_addr);

        connect(sock, (sockaddr*)&addr, sizeof(addr));

        // Log handshake completion (FR-01)
        Logger::getInstance().log("client.log", INFO, "Handshake completed");

        int choice;
        std::string user, pass;

        /*
         * ----------------------------------------------------
         *  Display Interactive Menu
         * ----------------------------------------------------
         */
        std::cout << "\n========= ECSBF NODE =========\n";
        std::cout << "1. Register\n";
        std::cout << "2. Login\n";
        std::cout << "3. Exit\n";
        std::cout << "Choose option: ";
        std::cin >> choice;

        /*
         * Validate numeric input integrity
         */
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input!.\n Enter numeric option.\n";
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        /*
         * Validate menu option range
         */
        if (choice < 1 || choice > 3) {
            std::cout << "Invalid option! Please choose 1, 2 or 3.\n";
            continue;
        }

        /*
         * Immediate exit option
         */
        if (choice == 3) {
            std::cout << "Client shutdown requested.\n";
            close(sock);
            return;
        }

        /*
         * ----------------------------------------------------
         *  Collect and validate user credentials
         * ----------------------------------------------------
         */
        std::cout << "Enter UserID: ";
        std::getline(std::cin, user);

        bool valid = true;
        for (char c : user) {
            if (!isalnum(c)) {   // Restrict to alphanumeric only
                valid = false;
                break;
            }
        }

        if (!valid || user.empty()) {
            std::cout << "Invalid UserID. Only letters and numbers allowed.\n";
            close(sock);
            continue;
        }

        std::cout << "Enter Password: ";
        std::getline(std::cin, pass);

        /*
         * ----------------------------------------------------
         *  Registration Flow (FR-02)
         * ----------------------------------------------------
         */
        if (choice == 1) {

            NetworkUtil::sendPacket(sock, "REGISTER|" + user + "|" + pass);
            std::string resp = NetworkUtil::receivePacket(sock);

            std::cout << resp << std::endl;

            if (resp == "REGISTER_SUCCESS") {
                std::cout << "Please login to continue.\n";
            }

            close(sock);
            continue;
        }

        /*
         * ----------------------------------------------------
         *  Login Flow (FR-03)
         * ----------------------------------------------------
         */
        if (choice == 2) {

            NetworkUtil::sendPacket(sock, "LOGIN|" + user + "|" + pass);
            std::string resp = NetworkUtil::receivePacket(sock);

            if (resp.find("LOGIN_SUCCESS") == 0) {

                // Extract session encryption key from response
                size_t pos = resp.find('|');
                sessionKey = resp.substr(pos + 1);

                std::cout << "LOGIN_SUCCESS\n";

            } else {

                std::cout << "LOGIN_FAILED\n";
                close(sock);
                continue;
            }
        }

        /*
         * ----------------------------------------------------
         *  Secure Chat Communication Phase
         * ----------------------------------------------------
         */
        std::cout << "You can now chat. \n Type 'exit' to quit.\n";

        running = true;

        // Spawn background thread for receiving broadcasts
        std::thread receiver(&Client::listenForMessages, this);

        while (true) {

            std::string msg;
            std::getline(std::cin, msg);

            /*
             * Controlled shutdown sequence.
             */
            if (msg == "exit") {
                running = false;
                shutdown(sock, SHUT_RDWR);
                break;
            }

            /*
             * Encrypt outgoing message using session key (FR-10)
             */
            std::string encrypted =
                CryptoUtil::encrypt(msg, sessionKey);

            NetworkUtil::sendPacket(sock, encrypted);
        }

        /*
         * Ensure receiver thread joins cleanly
         */
        if (receiver.joinable()) {
            receiver.join();
        }

        close(sock);

        break;
    }
}
