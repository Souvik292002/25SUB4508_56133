#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in address{};
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    bind(server_fd, (struct sockaddr*)&address, sizeof(address));
    listen(server_fd, 3);

    std::cout << "Server running on port 8080..." << std::endl;

    while (true) {
        int client = accept(server_fd, nullptr, nullptr);

        const char* response =
            "HTTP/1.1 200 OK\n"
            "Content-Type: text/plain\n\n"
            "Hello from C++ Docker container!";

        send(client, response, strlen(response), 0);
        close(client);
    }
}
