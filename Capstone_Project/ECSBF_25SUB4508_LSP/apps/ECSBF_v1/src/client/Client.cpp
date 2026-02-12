#include <Client.h>
#include <NetworkUtil.h>
#include <Logger.h>
#include <CryptoUtil.h>

#include <iostream>
#include <thread>
#include <atomic>
#include <unistd.h>
#include <arpa/inet.h>
#include <limits>

/* ============================================================
 *  Global Execution Control Flag
 * ============================================================ */
static std::atomic<bool> running(true);


/* ============================================================
 *  Constructor
 * ============================================================ */
Client::Client(const std::string& ip, int port)
    : sock(-1), serverIp(ip), serverPort(port) {}


/* ============================================================
 *  Receiver Thread
 * ============================================================ */
void Client::listenForMessages() {

    while (running) {

        std::string encryptedMsg =
            NetworkUtil::receivePacket(sock);

        if (!running || encryptedMsg.empty())
            break;

        /* ---------------------------------------
         *  Decrypt Incoming Packet
         * --------------------------------------- */
        std::string decrypted =
            CryptoUtils::decrypt(encryptedMsg, sessionKey);

        std::cout << decrypted << std::endl;
    }
}


/* ============================================================
 *  Connect to ECSBF Core Engine
 * ============================================================ */
void Client::connectToEngine() {

    while (true) {

        /* ----------------------------------------------------
         *  Create Fresh Socket Connection
         * ---------------------------------------------------- */
        sock = socket(AF_INET, SOCK_STREAM, 0);

        sockaddr_in addr{};
        addr.sin_family = AF_INET;
        addr.sin_port   = htons(serverPort);
        inet_pton(AF_INET, serverIp.c_str(), &addr.sin_addr);

        if (connect(sock, (sockaddr*)&addr, sizeof(addr)) < 0) {
            Logger::error("Connection failed");
            return;
        }

        Logger::info("Handshake completed");

        /* ----------------------------------------------------
         *  MENU
         * ---------------------------------------------------- */
        int choice;

        std::cout << "\n========= ECSBF NODE =========\n";
        std::cout << "1. Register\n";
        std::cout << "2. Login\n";
        std::cout << "3. Exit\n";
        std::cout << "Choose option: ";

        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid choice.\n";
            close(sock);
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (choice == 3) {
            std::cout << "Client shutdown requested.\n";
            close(sock);
            return;
        }

        std::string user, pass;

        std::cout << "Enter UserID: ";
        std::getline(std::cin, user);

        std::cout << "Enter Password: ";
        std::getline(std::cin, pass);


        /* =====================================================
         *  REGISTRATION
         * ===================================================== */
        if (choice == 1) {

            NetworkUtil::sendPacket(sock,
                "REGISTER|" + user + "|" + pass);

            std::string resp =
                NetworkUtil::receivePacket(sock);

            std::cout << resp << std::endl;

            close(sock);
            continue;
        }


        /* =====================================================
         *  LOGIN
         * ===================================================== */
        if (choice == 2) {

            NetworkUtil::sendPacket(sock,
                "LOGIN|" + user + "|" + pass);

            std::string resp =
                NetworkUtil::receivePacket(sock);

            if (resp.find("LOGIN_SUCCESS") == 0) {

                /* Extract session key */
                size_t sep = resp.find('|');

                if (sep != std::string::npos) {
                    sessionKey = resp.substr(sep + 1);
                }

                std::cout << "LOGIN_SUCCESS\n";

            } else {
                std::cout << "LOGIN_FAILED\n";
                close(sock);
                continue;
            }
        }


        /* =====================================================
         *  CHAT MODE
         * ===================================================== */
        std::cout << "\nYou can now chat.\n";
        std::cout << "Type 'exit' to quit.\n\n";

        running = true;

        std::thread receiver(
            &Client::listenForMessages,
            this
        );

        while (true) {

            std::string msg;
            std::getline(std::cin, msg);

            if (msg == "exit") {
                running = false;
                shutdown(sock, SHUT_RDWR);
                break;
            }

            /* Encrypt before sending */
            std::string encrypted =
                CryptoUtils::encrypt(msg, sessionKey);

            NetworkUtil::sendPacket(sock, encrypted);
        }

        receiver.join();
        close(sock);

        break;  // exit after chat session
    }
}
