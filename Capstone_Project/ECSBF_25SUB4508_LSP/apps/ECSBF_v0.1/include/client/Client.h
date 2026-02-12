#ifndef CLIENT_H
#define CLIENT_H

#include <string>

class Client {
private:
    int sock;
    std::string serverIp;
    int serverPort;

    void listenForMessages();

public:
    Client(const std::string& ip, int port);

    void connectToEngine();
};

#endif
