#include <iostream>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

int main() {
    try {
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0)
            throw std::runtime_error("Socket creation failed");

        sockaddr_in serv{};
        serv.sin_family = AF_INET;
        serv.sin_port = htons(8080);

        if (inet_pton(AF_INET, "127.0.0.1", &serv.sin_addr) <= 0)
            throw std::runtime_error("Invalid address");

        if (connect(sock, (struct sockaddr*)&serv, sizeof(serv)) < 0)
            throw std::runtime_error("Connection failed");

        std::cout << "1. Admin Login\nChoice: ";
        int choice;
        std::cin >> choice;

        if (choice == 1) {
            send(sock, "ADMIN", strlen("ADMIN"), 0);
        }
        else {
            throw std::invalid_argument("Invalid menu choice");
        }

        close(sock);
    }
    catch (const std::exception& e) {
        std::cerr << "[Client Error] " << e.what() << std::endl;
    }
}
