#include <ECSBF_CoreEngine.h>
#include <Logger.h>
#include <NetworkUtil.h>

#include <unistd.h>
#include <arpa/inet.h>
#include <thread>
#include <CryptoUtil.h>
#include <unordered_map>
#include <string>
#include <iostream>
#include <mutex>

/*
 * ============================================================
 *  ECSBF_CoreEngine Constructor
 * ============================================================
 */
ECSBF_CoreEngine::ECSBF_CoreEngine(int port)
    : port(port), clientCounter(0) {}


/*
 * ============================================================
 *  Start ECSBF Core Engine
 * ============================================================
 */void ECSBF_CoreEngine::startEngine() {
    try{
    Logger::info("Starting ECSBF Engine...");

    /* ================= SOCKET CREATION ================= */
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0) {
        Logger::error("Socket creation failed");
        return;
    }
    Logger::info("Server socket created successfully");

    sockaddr_in serverAddr{};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(port);

    if (bind(serverSocket,
             (sockaddr*)&serverAddr,
             sizeof(serverAddr)) < 0) {

        Logger::error("Bind failed");
        close(serverSocket);
        return;
    }
    Logger::info("Bind successful on port " + std::to_string(port));

    if (listen(serverSocket, 5) < 0) {
        Logger::error("Listen failed");
        close(serverSocket);
        return;
    }
    Logger::info("Server now listening for connections");

    /* ================= ACCEPT LOOP ================= */
    while (true) {

        int clientSock = accept(serverSocket, nullptr, nullptr);
        if (clientSock < 0) {
            Logger::error("Accept failed");
            continue;
        }

        Logger::info("New client connection accepted");

        /* ========== SINGLE THREAD PER CLIENT ========== */
        std::thread([this, clientSock]() {

            try {

                /* ----------- RECEIVE FIRST REQUEST ----------- */
                std::string request =
                    NetworkUtil::receivePacket(clientSock);

                /* ================= REGISTER ================= */
                if (request.find("REGISTER") == 0) {

                    size_t first  = request.find('|');
                    size_t second = request.find('|', first + 1);

                    std::string nodeId =
                        request.substr(first + 1, second - first - 1);
                    std::string pass =
                        request.substr(second + 1);

                    registry.registerNode(NodeIdentity(nodeId, pass));
                    NetworkUtil::sendPacket(clientSock, "REGISTER_SUCCESS");

                    Logger::info("New node registered: " + nodeId);

                    close(clientSock);
                    return;
                }

                /* ================= LOGIN ================= */
                if (request.find("LOGIN") == 0) {

                    size_t first  = request.find('|');
                    size_t second = request.find('|', first + 1);

                    std::string nodeId =
                        request.substr(first + 1, second - first - 1);
                    std::string pass =
                        request.substr(second + 1);

                    if (!registry.authenticate(nodeId, pass)) {
                        NetworkUtil::sendPacket(clientSock, "LOGIN_FAILED");
                        Logger::warning("Login failed for node: " + nodeId);
                        close(clientSock);
                        return;
                    }

                    /* Assign numeric ID */
                    if (nodeNumericId.find(nodeId) == nodeNumericId.end()) {
                        clientCounter++;
                        nodeNumericId[nodeId] = clientCounter;
                    }

                    int numericId = nodeNumericId[nodeId];

                    Logger::info("Node-" +
                        std::to_string(numericId) + " connected");

                    /* Session management */
                    auto it = sessions.find(nodeId);
                    if (it != sessions.end())
                        it->second.restore();
                    else
                        sessions.emplace(nodeId,
                            Session("sess_" + nodeId, nodeId));

                    socketToNode[clientSock] = nodeId;

                    /* Generate session key ONCE */
                    std::string sessionKey =
                        CryptoUtil::generateKey();

                    sessionKeys[nodeId] = sessionKey;

                    NetworkUtil::sendPacket(
                        clientSock,
                        "LOGIN_SUCCESS|" + sessionKey
                    );

                    Logger::info("Session key generated for Node-" +
                        std::to_string(numericId));
                }
                else {
                    close(clientSock);
                    return;
                }

                /* ================= MESSAGE LOOP ================= */
                while (true) {

                    std::string encryptedMsg =
                        NetworkUtil::receivePacket(clientSock);

                    if (encryptedMsg.empty())
                        break;

                    std::string sender =
                        socketToNode[clientSock];

                    if (sessionKeys.find(sender) == sessionKeys.end()) {
                        Logger::error("Session key missing for " + sender);
                        break;
                    }

                    std::string senderKey =
                        sessionKeys[sender];

                    std::string decrypted =
                        CryptoUtil::decrypt(encryptedMsg, senderKey);

                    int numericId =
                        nodeNumericId[sender];

                    std::string finalMessage =
                        "Packet sent by Node-" +
                        std::to_string(numericId) +
                        ": " + decrypted;

                    Logger::logToNode(sender,
                        "Encrypted: " + encryptedMsg);
                    Logger::logToNode(sender,
                        "Decrypted: " + decrypted);

                    /* Broadcast */
                    for (auto& [nodeId, session] : sessions) {

                        if (session.isActive() &&
                            nodeId != sender &&
                            sessionKeys.find(nodeId) != sessionKeys.end()) {

                            std::string receiverKey =
                                sessionKeys[nodeId];

                            std::string reEncrypted =
                                CryptoUtil::encrypt(finalMessage,
                                                    receiverKey);

                            for (auto& [sock, mappedNode] : socketToNode) {
                                if (mappedNode == nodeId) {
                                    NetworkUtil::sendPacket(sock, reEncrypted);
                                    Logger::logToNode(nodeId,
                                        "Received: " + finalMessage);
                                }
                            }
                        }
                    }
                }
/* ================= CLEANUP ================= */

std::string disconnectedNode = "UNKNOWN";

auto sockIt = socketToNode.find(clientSock);

if (sockIt != socketToNode.end()) {

    disconnectedNode = sockIt->second;

    /* Remove session key */
    sessionKeys.erase(disconnectedNode);

    /* Invalidate session safely */
    auto it = sessions.find(disconnectedNode);
    if (it != sessions.end()) {
        it->second.invalidate();
    }

    /* Remove socket mapping */
    socketToNode.erase(sockIt);
}

close(clientSock);

Logger::info("Client disconnected: " + disconnectedNode);

            }
            catch (const std::exception& e) {
                Logger::error(std::string("Thread exception: ") + e.what());
            }
            catch (...) {
                Logger::error("Unknown exception in client thread");
            }

        }).detach();
    }
}
catch (const std::exception& e) {
        Logger::error(
            "Engine fatal exception: " + std::string(e.what())
        );
    }
    catch (...) {
        Logger::error(
            "Unknown fatal exception in engine"
        );
    }
}