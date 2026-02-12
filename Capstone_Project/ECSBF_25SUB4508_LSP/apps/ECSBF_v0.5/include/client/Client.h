#ifndef CLIENT_H
#define CLIENT_H

#include <string>

class Client {
private:
    int sock;
    std::string serverIp;
    int serverPort;

    /* --------------------------------------------------------
     *  Session Encryption Key
     * --------------------------------------------------------
     *  Unique symmetric key assigned by ECSBF Core Engine
     *  after successful authentication.
     *
     *  Used for:
     *   - Encrypting outgoing messages
     *   - Decrypting incoming messages
     */
    std::string sessionKey;

    void listenForMessages();

public:
    Client(const std::string& ip, int port);
    void connectToEngine();
};

#endif
