#ifndef SERVER_H
#define SERVER_H

#include "ClientManager.h"

class Server {
private:
    int serverFd;
    int port;
    ClientManager clientManager;

public:
    Server(int port);
    void start();
};

#endif
