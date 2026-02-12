// #include "ECSBF_CoreEngine.h"
// #include "Logger.h"
// #include "NetworkUtil.h"

// #include <unistd.h>
// #include <arpa/inet.h>
// #include <thread>

// ECSBF_CoreEngine::ECSBF_CoreEngine(int port)
//     : port(port) {}

// void ECSBF_CoreEngine::startEngine() {
//     Logger::info("Starting ECSBF Engine...");

//     serverSocket = socket(AF_INET, SOCK_STREAM, 0);

//     sockaddr_in serverAddr{};
//     serverAddr.sin_family = AF_INET;
//     serverAddr.sin_addr.s_addr = INADDR_ANY;
//     serverAddr.sin_port = htons(port);

//     bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr));
//     listen(serverSocket, 5);

//     Logger::info("ECSBF Engine listening on port " + std::to_string(port));

//     while (true) {
//         int clientSock = accept(serverSocket, nullptr, nullptr);

//         std::thread([this, clientSock]() {

//             Logger::info("Node connected to ECSBF Engine");

//             std::string request = NetworkUtil::receivePacket(clientSock);

//             /* ---------------- REGISTER ---------------- */
//             if (request.find("REGISTER") == 0) {

//     size_t first = request.find('|');
//     size_t second = request.find('|', first + 1);

//     std::string nodeId = request.substr(first + 1, second - first - 1);
//     std::string pass   = request.substr(second + 1);

//     registry.registerNode(NodeIdentity(nodeId, pass));
//     NetworkUtil::sendPacket(clientSock, "REGISTER_SUCCESS");

//     close(clientSock);
//     return;
// }


//             /* ---------------- LOGIN ---------------- */
//             if (request.find("LOGIN") == 0) {

//     size_t first = request.find('|');
//     size_t second = request.find('|', first + 1);

//     std::string nodeId = request.substr(first + 1, second - first - 1);
//     std::string pass   = request.substr(second + 1);

//     if (!registry.authenticate(nodeId, pass)) {
//         NetworkUtil::sendPacket(clientSock, "LOGIN_FAILED");
//         close(clientSock);
//         return;
//     }

//     std::string sessionId = "sess_" + nodeId;
//     sessions.emplace(clientSock, Session(sessionId, nodeId));

//     NetworkUtil::sendPacket(clientSock, "LOGIN_SUCCESS");
// }
// else {
//     close(clientSock);
//     return;
// }


//             /* ---------------- MESSAGE BROADCAST ---------------- */
//             while (true) {
//                 std::string msg = NetworkUtil::receivePacket(clientSock);
//                 if (msg.empty()) break;

//                 auto senderIt = sessions.find(clientSock);
//                 if (senderIt == sessions.end()) break;

//                 std::string sender = senderIt->second.getNodeId();

//                 for (auto& s : sessions) {
//                     if (s.first != clientSock) {
//                         NetworkUtil::sendPacket(
//                             s.first,
//                             "Message sent by " + sender + ": " + msg
//                         );
//                     }
//                 }
//             }

//             /* ---------------- CLEANUP ---------------- */
//             sessions.erase(clientSock);
//             close(clientSock);
//             Logger::info("Node disconnected");

//         }).detach();
//     }
// } 


#include "ECSBF_CoreEngine.h"
#include "Logger.h"
#include "NetworkUtil.h"

#include <unistd.h>
#include <arpa/inet.h>
#include <thread>

ECSBF_CoreEngine::ECSBF_CoreEngine(int port)
    : port(port) {}

void ECSBF_CoreEngine::startEngine() {
    Logger::info("Starting ECSBF Engine...");

    serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in serverAddr{};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(port);

    bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr));
    listen(serverSocket, 5);

    Logger::info("ECSBF Engine listening on port " + std::to_string(port));

    while (true) {
        int clientSock = accept(serverSocket, nullptr, nullptr);

        std::thread([this, clientSock]() {

            Logger::info("Node connected to ECSBF Engine");

            std::string request = NetworkUtil::receivePacket(clientSock);

            /* ---------------- REGISTER ---------------- */
            if (request.find("REGISTER") == 0) {

                size_t first = request.find('|');
                size_t second = request.find('|', first + 1);

                std::string nodeId = request.substr(first + 1, second - first - 1);
                std::string pass   = request.substr(second + 1);

                registry.registerNode(NodeIdentity(nodeId, pass));
                NetworkUtil::sendPacket(clientSock, "REGISTER_SUCCESS");

                close(clientSock);
                return;
            }

            /* ---------------- LOGIN ---------------- */
            if (request.find("LOGIN") == 0) {

                size_t first = request.find('|');
                size_t second = request.find('|', first + 1);

                std::string nodeId = request.substr(first + 1, second - first - 1);
                std::string pass   = request.substr(second + 1);

                if (!registry.authenticate(nodeId, pass)) {
                    NetworkUtil::sendPacket(clientSock, "LOGIN_FAILED");
                    close(clientSock);
                    return;
                }

                /* -------- SESSION RESTORE / CREATE -------- */
                auto it = sessions.find(nodeId);
                if (it != sessions.end()) {
                    it->second.restore();
                    Logger::info("Restoring existing session for node " + nodeId);
                } else {
                    sessions.emplace(nodeId, Session("sess_" + nodeId, nodeId));
                    Logger::info("Creating new session for node " + nodeId);
                }

                socketToNode[clientSock] = nodeId;
                NetworkUtil::sendPacket(clientSock, "LOGIN_SUCCESS");
            }
            else {
                close(clientSock);
                return;
            }

            /* ---------------- MESSAGE BROADCAST ---------------- */
            while (true) {
                std::string msg = NetworkUtil::receivePacket(clientSock);
                if (msg.empty()) break;

                auto sockIt = socketToNode.find(clientSock);
                if (sockIt == socketToNode.end()) break;

                std::string sender = sockIt->second;

                for (auto& [nodeId, session] : sessions) {
                    if (session.isActive() && nodeId != sender) {
                        for (auto& [sock, mappedNode] : socketToNode) {
                            if (mappedNode == nodeId) {
                                NetworkUtil::sendPacket(
                                    sock,
                                    "Message sent by " + sender + ": " + msg
                                );
                            }
                        }
                    }
                }
            }

            /* ---------------- CLEANUP ---------------- */
            auto sockIt = socketToNode.find(clientSock);
            if (sockIt != socketToNode.end()) {
                std::string nodeId = sockIt->second;

                auto sessIt = sessions.find(nodeId);
                if (sessIt != sessions.end()) {
                    sessIt->second.invalidate();   // session persists
                }

                socketToNode.erase(sockIt);
            }

            close(clientSock);
            Logger::info("Node disconnected");

        }).detach();
    }
}
