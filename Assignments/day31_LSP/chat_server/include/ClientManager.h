#ifndef CLIENT_MANAGER_H
#define CLIENT_MANAGER_H

#include <vector>

class ClientManager {
private:
    std::vector<int> clients;

public:
    void addClient(int fd);
    void removeClient(int fd);
    void broadcastMessage(int senderFd, const char* buffer);
    const std::vector<int>& getClients() const;
};

#endif
