#include "Server.h"
#include "Utils.h"

#include <arpa/inet.h>
#include <unistd.h>
#include <sys/select.h>
#include <cstring>

Server::Server(int port) : serverFd(-1), port(port) {}


void Server::start() {
    sockaddr_in serverAddr{};

    serverFd = socket(AF_INET, SOCK_STREAM, 0);
    if (serverFd < 0) {
        printError("Socket creation failed.");
        return;
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    if (bind(serverFd, (sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        printError("Bind failed. Port may already be in use.");
        close(serverFd);
        return;
    }

    if (listen(serverFd, 5) < 0) {
        printError("Listen failed.");
        close(serverFd);
        return;
    }

    printInfo("Server started on port " + std::to_string(port));

    fd_set masterSet, readSet;
    FD_ZERO(&masterSet);
    FD_SET(serverFd, &masterSet);

    int maxFd = serverFd;

    while (true) {
        readSet = masterSet;

        if (select(maxFd + 1, &readSet, nullptr, nullptr, nullptr) < 0) {
            printError("Select system call failed.");
            break;
        }

        for (int fd = 0; fd <= maxFd; fd++) {
            if (FD_ISSET(fd, &readSet)) {

                // New client connection
                if (fd == serverFd) {
                    int clientFd = accept(serverFd, nullptr, nullptr);
                    if (clientFd < 0) {
                        printError("Accept failed.");
                        continue;
                    }

                    FD_SET(clientFd, &masterSet);
                    maxFd = std::max(maxFd, clientFd);
                    clientManager.addClient(clientFd);
                }
                // Existing client message
                else {
                    char buffer[1025];
                    int bytes = recv(fd, buffer, sizeof(buffer), 0);

                    if (bytes <= 0) {
                        FD_CLR(fd, &masterSet);
                        clientManager.removeClient(fd);
                    } else {
                        buffer[bytes] = '\0';
                        clientManager.broadcastMessage(fd, buffer);
                    }
                }
            }
        }
    }

    close(serverFd);
}
