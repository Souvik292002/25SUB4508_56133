#include "NetworkUtil.h"
#include <unistd.h>
#include <sys/socket.h>

void NetworkUtil::sendPacket(int sock, const std::string& data) {
    send(sock, data.c_str(), data.size(), 0);
}

std::string NetworkUtil::receivePacket(int sock) {
    char buffer[1024] = {0};
    recv(sock, buffer, sizeof(buffer), 0);
    return std::string(buffer);
}
