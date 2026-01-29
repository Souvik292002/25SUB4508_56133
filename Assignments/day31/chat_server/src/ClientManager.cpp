#include "ClientManager.h"
#include "Utils.h"
#include <unistd.h>
#include <cstring>
#include <algorithm>

void ClientManager::addClient(int fd) {
    clients.push_back(fd);
    printInfo("New client connected. FD: " + std::to_string(fd));
}

void ClientManager::removeClient(int fd) {
    clients.erase(
        std::remove(clients.begin(), clients.end(), fd),
        clients.end()
    );
    close(fd);
    printInfo("Client disconnected. FD: " + std::to_string(fd));
}

void ClientManager::broadcastMessage(int senderFd, const char* buffer) {
    for (int client : clients) {
        if (client != senderFd) {
            if (send(client, buffer, strlen(buffer), 0) < 0) {
                printError("Failed to send message to client FD: " + std::to_string(client));
            }
        }
    }
}

const std::vector<int>& ClientManager::getClients() const {
    return clients;
}
