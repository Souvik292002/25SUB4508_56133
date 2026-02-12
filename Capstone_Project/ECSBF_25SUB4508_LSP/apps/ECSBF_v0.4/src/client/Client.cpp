#include <Client.h>
#include <NetworkUtil.h>
#include <Logger.h>

#include <iostream>
#include <thread>
#include <atomic>
#include <unistd.h>
#include <arpa/inet.h>

/*
 * ------------------------------------------------------------
 *  Global Execution Control Flag
 * ------------------------------------------------------------
 *  Controls the lifecycle of the background receiver thread.
 *
 *  Atomic semantics are used to ensure safe access across
 *  multiple threads without requiring explicit locks.
 *
 *  This flag enables graceful shutdown of the client’s
 *  asynchronous message listener.
 * ------------------------------------------------------------
 */
static std::atomic<bool> running(true);

/* ============================================================
 *  Constructor
 * ============================================================
 *  Initializes the client with ECSBF Core Engine connection
 *  parameters.
 *
 *  Note:
 *  - Socket creation and connection establishment are deferred
 *    to connectToEngine()
 *  - Socket descriptor is initialized to an invalid state
 * ============================================================
 */
Client::Client(const std::string& ip, int port)
    : sock(-1), serverIp(ip), serverPort(port) {}


/* ============================================================
 *  Receiver Thread
 * ============================================================
 *  Continuously listens for incoming packet from the ECSBF
 *  Core Engine.
 *
 *  Design Intent:
 *  - Executes in a dedicated thread
 *  - Enables non-blocking reception of broadcast or direct
 *    packet
 *  - Terminates gracefully when the global running flag is
 *    cleared or when the socket is shut down
 *
 *  This method represents the client-side asynchronous
 *  signal reception pipeline.
 * ============================================================
 */
void Client::listenForMessages() {
    while (running) {
        std::string msg = NetworkUtil::receivePacket(sock);

        /*
         * Exit conditions:
         *  - Global shutdown requested
         *  - Remote endpoint closed connection
         */
        if (!running || msg.empty())
            break;

        /*
         * Incoming packet are written directly to stdout.
         * Presentation logic is intentionally minimal to keep
         * networking concerns isolated.
         */
        std::cout << msg << std::endl;
    }
}


/* ============================================================
 *  Connect to ECSBF Core Engine
 * ============================================================
 *  Establishes a TCP connection to the Core Engine and manages
 *  the complete client lifecycle:
 *
 *   - Connection establishment
 *   - Registration / authentication handshake
 *   - Transition into interactive chat mode
 *   - Graceful shutdown
 *
 *  This method serves as the primary execution entry point
 *  for the ECSBF client endpoint.
 * ============================================================
 */
void Client::connectToEngine() {

    /*
     * Outer loop allows controlled retries for registration
     * and authentication failures without terminating the
     * client process.
     */
    while (true) {

        /* ----------------------------------------------------
         *  Create Fresh Socket Connection
         * ----------------------------------------------------
         *  A new socket is created for each authentication
         *  attempt to ensure clean connection state.
         * ----------------------------------------------------
         */
        sock = socket(AF_INET, SOCK_STREAM, 0);

        sockaddr_in addr{};
        addr.sin_family = AF_INET;
        addr.sin_port = htons(serverPort);
        inet_pton(AF_INET, serverIp.c_str(), &addr.sin_addr);

        connect(sock, (sockaddr*)&addr, sizeof(addr));
        Logger::info("Handshake completed");

        int choice;
        std::string user, pass;

        /*
         * ----------------------------------------------------
         *  Authentication Menu
         * ----------------------------------------------------
         *  Allows the user to either register a new identity
         *  or authenticate an existing one.
         * ----------------------------------------------------
         */
        // std::cout << "\nEnter 1 to Register\n";
        // std::cout << "Enter 2 to Login\n";
        // std::cout << "Choice: ";
        // std::cin >> choice;

        std::cout << "\n========= ECSBF NODE =========\n";
std::cout << "1. Register\n";
std::cout << "2. Login\n";
std::cout << "3. Exit\n";
std::cout << "Choose option: ";
std::cin >> choice;


        /*
         * Input validation to protect against invalid
         * or malformed user input.
         */
        if (std::cin.fail()) {
            std::cin.clear(); // reset fail state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid choice.\n Please enter 1 or 2.\n";
            continue;
        }

        // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
         std::cin.ignore();

         /* ----------------------------------------------------
         *  Immediate Exit Option
         * ---------------------------------------------------- */
        if (choice == 3) {
            std::cout << "Client shutdown requested.\n";
            close(sock);
            return;
        }
        /*
         * Collect user credentials.
         */
        std::cout << "Enter UserID: ";
        std::getline(std::cin, user);

//         // USERNAME VALIDATION (only alphabets allowed)
// bool valid = true;

// for (char c : user) {
//     if (!isalpha(c)) {
//         valid = false;
//         break;
//     }
// }

// if (!valid || user.empty()) {
//     std::cout << "Invalid UserID. Only alphabets allowed.\n";
//     close(sock);
//     continue;   // restart menu
// }


        std::cout << "Enter Password: ";
        std::getline(std::cin, pass);

        /* ----------------------------------------------------
         *  Registration Workflow
         * ----------------------------------------------------
         *  Sends registration request to the Core Engine.
         *
         *  After registration, the connection is closed and
         *  the user is returned to the menu.
         * ----------------------------------------------------
         */
        // if (choice == 1) {
        //     NetworkUtil::sendPacket(sock, "REGISTER|" + user + "|" + pass);
        //     std::string resp = NetworkUtil::receivePacket(sock);
        //     std::cout << resp << std::endl;

        //     close(sock);
        //     continue;
        // }

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


        /* ----------------------------------------------------
         *  Authentication Workflow
         * ----------------------------------------------------
         *  Validates user credentials against the Core Engine.
         *
         *  Only successful authentication allows transition
         *  into interactive chat mode.
         * ----------------------------------------------------
         */
        if (choice == 2) {
            NetworkUtil::sendPacket(sock, "LOGIN|" + user + "|" + pass);
            std::string resp = NetworkUtil::receivePacket(sock);
            std::cout << resp << std::endl;

            if (resp != "LOGIN_SUCCESS") {
                close(sock);
                continue;
            }
        }

        

        /* ----------------------------------------------------
         *  Interactive Chat Mode
         * ----------------------------------------------------
         *  - Spawns a receiver thread for inbound packet
         *  - Main thread handles outbound user input
         * ----------------------------------------------------
         */
        std::cout << "You can now chat. \n Type 'exit' to quit.\n";

        running = true;
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

            NetworkUtil::sendPacket(sock, msg);
        }

        /*
         * Ensure receiver thread terminates cleanly
         * before releasing socket resources.
         */
        receiver.join();
        close(sock);

        /*
         * Exit client after chat session ends.
         */
        break;
    }
}
