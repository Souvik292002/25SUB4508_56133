#include <iostream>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include "state_manager.h"

#define UDP_PORT 9000
#define BUFFER_SIZE 1024

void startVitalReceiver(StateManager& stateManager) {
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("UDP socket failed");
        return;
    }

    sockaddr_in serverAddr{};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(UDP_PORT);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    bind(sockfd, (sockaddr*)&serverAddr, sizeof(serverAddr));

    char buffer[BUFFER_SIZE];

    while (true) {
        ssize_t bytes = recvfrom(sockfd, buffer, BUFFER_SIZE - 1, 0, nullptr, nullptr);
        if (bytes < 0) continue;

        buffer[bytes] = '\0';
        stateManager.processVitalMessage(buffer);
    }
}
