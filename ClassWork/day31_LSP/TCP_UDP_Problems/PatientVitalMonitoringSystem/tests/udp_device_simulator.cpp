#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

int main() {
    int sock = socket(AF_INET, SOCK_DGRAM, 0);

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(9000);
    addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);

    const char* msg = "P001,130,85,40";

    sendto(sock, msg, strlen(msg), 0,
           (sockaddr*)&addr, sizeof(addr));

    close(sock);
    return 0;
}
