#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    const char *message = "Welcome to the Server!";

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(server_fd, 3);

    std::cout << "Server listening on port 8080..." << std::endl;

    new_socket = accept(server_fd, (struct sockaddr *)&address,
                        (socklen_t *)&addrlen);

    send(new_socket, message, strlen(message), 0);
    std::cout << "Message sent to client" << std::endl;

    close(new_socket);
    close(server_fd);

    return 0;
}
