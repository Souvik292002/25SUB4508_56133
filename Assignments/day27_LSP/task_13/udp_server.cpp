#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int sockfd;
    char buffer[1024];
    struct sockaddr_in servaddr, cliaddr;
    socklen_t len;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(9090);

    bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    std::cout << "UDP Server is running..." << std::endl;

    len = sizeof(cliaddr);
    recvfrom(sockfd, buffer, sizeof(buffer), 0,
             (struct sockaddr *)&cliaddr, &len);

    std::cout << "Message from client: " << buffer << std::endl;

    const char *reply = "Hello from Server";
    sendto(sockfd, reply, strlen(reply), 0,
           (struct sockaddr *)&cliaddr, len);

    close(sockfd);
    return 0;
}
