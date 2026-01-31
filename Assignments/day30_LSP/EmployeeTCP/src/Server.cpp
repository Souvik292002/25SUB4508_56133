#include <iostream>
#include <thread>
#include <stdexcept>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include "EmployeeDatabase.h"

EmployeeDatabase db;

void handleClient(int clientSocket) {
    try {
        char buffer[1024] = {0};
        int bytesRead = read(clientSocket, buffer, sizeof(buffer));

        if (bytesRead <= 0)
            throw std::runtime_error("Client disconnected unexpectedly");

        std::string request(buffer);

        if (request == "ADMIN") {
            db.viewAllEmployees();
        }
        else {
            throw std::invalid_argument("Unknown request");
        }
    }
    catch (const std::exception& e) {
        std::cerr << "[Client Error] " << e.what() << std::endl;
    }

    close(clientSocket);
}

int main() {
    try {
        int serverFd = socket(AF_INET, SOCK_STREAM, 0);
        if (serverFd < 0)
            throw std::runtime_error("Socket creation failed");

        sockaddr_in address{};
        address.sin_family = AF_INET;
        address.sin_port = htons(8080);
        address.sin_addr.s_addr = INADDR_ANY;

        if (bind(serverFd, (struct sockaddr*)&address, sizeof(address)) < 0)
            throw std::runtime_error("Bind failed");

        if (listen(serverFd, 10) < 0)
            throw std::runtime_error("Listen failed");

        std::cout << "Server running...\n";

        while (true) {
            int clientSocket = accept(serverFd, nullptr, nullptr);
            if (clientSocket < 0)
                throw std::runtime_error("Accept failed");

            std::thread(handleClient, clientSocket).detach();
        }
    }
    catch (const std::exception& e) {
        std::cerr << "[Server Fatal] " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
}
