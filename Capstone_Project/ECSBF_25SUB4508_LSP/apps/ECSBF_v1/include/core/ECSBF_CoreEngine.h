#pragma once

#include <mutex>
#include <unordered_map>
#include <string>

#include <registry/IdentityRegistry.h>
#include <Session.h>

class ECSBF_CoreEngine {
private:

    int port;
    int serverSocket;

    /* Thread safety */
    std::mutex engineMutex;

    /* FR-04 Persistent Sessions */
    std::unordered_map<std::string, Session> sessions;  
    // nodeId -> Session

    /* Socket mapping */
    std::unordered_map<int, std::string> socketToNode;  
    // socket -> nodeId

    /* Numeric ID mapping */
    int clientCounter = 0;
    std::unordered_map<std::string, int> nodeNumericId;

    /* Encryption session keys */
    std::unordered_map<std::string, std::string> sessionKeys;
    // nodeId -> sessionKey

    IdentityRegistry registry;

public:
    ECSBF_CoreEngine(int port);
    void startEngine();
};
