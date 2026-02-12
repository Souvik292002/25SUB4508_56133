#pragma once

#include <unordered_map>
#include <string>

#include "registry/IdentityRegistry.h"
#include "Session.h"

class ECSBF_CoreEngine {
private:
    int port;
    int serverSocket;

    // FR-04: Persistent session management
    std::unordered_map<std::string, Session> sessions;   // nodeId -> Session
    std::unordered_map<int, std::string> socketToNode;   // socket -> nodeId

    IdentityRegistry registry;

public:
    ECSBF_CoreEngine(int port);
    void startEngine();
};

