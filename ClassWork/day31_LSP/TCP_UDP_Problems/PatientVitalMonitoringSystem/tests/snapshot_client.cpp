#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>
#include <cstring>

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(9200);
    addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);

    connect(sock, (sockaddr*)&addr, sizeof(addr));

    const char* patientId = "P001";
    send(sock, patientId, strlen(patientId), 0);

    char buffer[256];
    int n = recv(sock, buffer, sizeof(buffer) - 1, 0);
    buffer[n] = '\0';

    std::cout << buffer << std::endl;

    close(sock);
    return 0;
}
