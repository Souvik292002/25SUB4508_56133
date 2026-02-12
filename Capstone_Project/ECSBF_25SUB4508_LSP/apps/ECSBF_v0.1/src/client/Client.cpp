#include "Client.h"
#include "NetworkUtil.h"
#include "Logger.h"

#include <iostream>
#include <thread>
#include <atomic>
#include <unistd.h>
#include <arpa/inet.h>

static std::atomic<bool> running(true);

/* ---------------- CONSTRUCTOR ---------------- */
// Client::Client(const std::string& ip, int port)
//     : serverIp(ip), serverPort(port), sock(-1) {}
Client::Client(const std::string& ip, int port)
    : sock(-1), serverIp(ip), serverPort(port) {}


/* ---------------- RECEIVER THREAD ---------------- */
void Client::listenForMessages() {
    while (running) {
        std::string msg = NetworkUtil::receivePacket(sock);
        if(!running || msg.empty()) break;
        // if (!msg.empty()) {
            std::cout << msg << std::endl;
        // }
    }
}

/* ---------------- CONNECT TO ENGINE ---------------- */
void Client::connectToEngine() {

    while (true) {

        /* ---------- create fresh connection ---------- */
        sock = socket(AF_INET, SOCK_STREAM, 0);

        sockaddr_in addr{};
        addr.sin_family = AF_INET;
        addr.sin_port = htons(serverPort);
        inet_pton(AF_INET, serverIp.c_str(), &addr.sin_addr);

        connect(sock, (sockaddr*)&addr, sizeof(addr));
        Logger::info("Handshake completed");

        int choice;
        std::string user, pass;

        std::cout << "\nEnter 1 to Register\n";
        std::cout << "Enter 2 to Login\n";
        std::cout << "Choice: ";
       std::cin >> choice;

if (std::cin.fail()) {
    std::cin.clear(); // reset fail state
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Invalid choice. Please enter 1 or 2.\n";
    continue;
}

std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Enter UserID: ";
        std::getline(std::cin, user);

        std::cout << "Enter Password: ";
        std::getline(std::cin, pass);

        /* ---------- REGISTER ---------- */
        if (choice == 1) {
            NetworkUtil::sendPacket(sock, "REGISTER|" + user + "|" + pass);
            std::string resp = NetworkUtil::receivePacket(sock);
            std::cout << resp << std::endl;

            close(sock);          // 🔥 server closes too
            continue;             // 🔥 show menu again
        }

        /* ---------- LOGIN ---------- */
        if (choice == 2) {
            NetworkUtil::sendPacket(sock, "LOGIN|" + user + "|" + pass);
            std::string resp = NetworkUtil::receivePacket(sock);
            std::cout << resp << std::endl;

            if (resp != "LOGIN_SUCCESS") {
                close(sock);
                continue;         // 🔥 retry menu
            }
        }

        /* ---------- CHAT MODE ---------- */
        std::cout << "You can now chat. Type 'exit' to quit.\n";

        running = true;
        std::thread receiver(&Client::listenForMessages, this);

        while (true) {
            std::string msg;
            std::getline(std::cin, msg);

            if (msg == "exit") {
                running = false;
                shutdown(sock, SHUT_RDWR);
                break;
            }

            NetworkUtil::sendPacket(sock, msg);
        }

        receiver.join();
        close(sock);
        break;    // exit client completely
    }
}
