#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int sockfd;
    char buffer[1024];
    struct sockaddr_in servaddr;
    socklen_t len;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(9090);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    const char *msg = "Hello from Client";
    sendto(sockfd, msg, strlen(msg), 0,
           (struct sockaddr *)&servaddr, sizeof(servaddr));

    len = sizeof(servaddr);
    recvfrom(sockfd, buffer, sizeof(buffer), 0,
             (struct sockaddr *)&servaddr, &len);

    std::cout << "Message from server: " << buffer << std::endl;

    close(sockfd);
    return 0;
}
