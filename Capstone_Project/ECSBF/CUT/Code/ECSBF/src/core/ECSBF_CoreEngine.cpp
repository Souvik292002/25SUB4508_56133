/**
 * @file ECSBF_CoreEngine.cpp
 * @brief Implements the ECSBF Core Engine — the centralized orchestration
 *        component of the Enterprise Concurrent Signal Broadcast Framework.
 *
 * Responsibilities:
 * - Initialize and manage server socket lifecycle
 * - Handle node registration (FR-02)
 * - Perform mandatory authentication (FR-03)
 * - Maintain persistent sessions (FR-04)
 * - Generate and manage encryption session keys (FR-10)
 * - Decrypt and re-encrypt broadcast messages (FR-11)
 * - Concurrently handle multiple node connections (FR-05)
 * - Broadcast signals to all active nodes (FR-06)
 * - Provide multi-level diagnostic logging (FR-12)
 */

#include <ECSBF_CoreEngine.h>
#include <Logger.h>
#include <NetworkUtil.h>
#include <CryptoUtil.h>

#include <unistd.h>
#include <arpa/inet.h>
#include <thread>
#include <string>

/**
 * ============================================================
 *  Constructor
 * ============================================================
 *
 * Initializes the ECSBF Core Engine with the specified port.
 * The engine remains dormant until startEngine() is invoked.
 */
ECSBF_CoreEngine::ECSBF_CoreEngine(int port)
    : port(port), clientCounter(0) {}


/**
 * ============================================================
 *  Start Engine
 * ============================================================
 *
 * Initializes networking resources and begins accepting
 * concurrent node connections.
 *
 * High-Level Flow:
 * 1. Create socket
 * 2. Bind to configured port
 * 3. Listen for connections
 * 4. Accept clients
 * 5. Spawn dedicated thread per client
 *
 * This method represents the runtime entry point
 * of the ECSBF Engine.
 */
void ECSBF_CoreEngine::startEngine() {

    Logger& logger = Logger::getInstance();
    logger.setLogLevel(DEBUG);   // Runtime log level configuration

    try {

        logger.log("engine.log", INFO, "Starting ECSBF Engine...");

        /* ================= SOCKET CREATION ================= */
        serverSocket = socket(AF_INET, SOCK_STREAM, 0);
        if (serverSocket < 0) {
            logger.log("engine.log", FATAL, "Socket creation failed");
            return;
        }

        logger.log("engine.log", INFO, "Server socket created successfully");

        sockaddr_in serverAddr{};
        serverAddr.sin_family = AF_INET;
        serverAddr.sin_addr.s_addr = INADDR_ANY;
        serverAddr.sin_port = htons(port);

        /* ================= BIND ================= */
        if (bind(serverSocket,
                 (sockaddr*)&serverAddr,
                 sizeof(serverAddr)) < 0) {

            logger.log("engine.log", FATAL, "Bind failed");
            close(serverSocket);
            return;
        }

        logger.log("engine.log", INFO,
            "Bind successful on port " + std::to_string(port));

        /* ================= LISTEN ================= */
        if (listen(serverSocket, 5) < 0) {
            logger.log("engine.log", FATAL, "Listen failed");
            close(serverSocket);
            return;
        }

        logger.log("engine.log", INFO, "Server now listening");

        /* ================= ACCEPT LOOP ================= */
        while (true) {

            int clientSock = accept(serverSocket, nullptr, nullptr);
            if (clientSock < 0) {
                logger.log("engine.log", WARNING, "Accept failed");
                continue;
            }

            logger.log("engine.log", INFO, "New client connected");

            /**
             * Each client is handled in a detached thread.
             * This ensures concurrent processing capability (FR-05).
             */
            std::thread([this, clientSock]() {

                Logger& logger = Logger::getInstance();

                try {

                    std::string request =
                        NetworkUtil::receivePacket(clientSock);

                    /* ===================================================
                     *  NODE REGISTRATION FLOW (FR-02)
                     * =================================================== */
                    if (request.find("REGISTER") == 0) {

                        size_t first  = request.find('|');
                        size_t second = request.find('|', first + 1);

                        std::string nodeId =
                            request.substr(first + 1,
                            second - first - 1);

                        std::string pass =
                            request.substr(second + 1);

                        registry.registerNode(
                            NodeIdentity(nodeId, pass));

                        NetworkUtil::sendPacket(
                            clientSock, "REGISTER_SUCCESS");

                        logger.log("engine.log", INFO,
                            "New node registered: " + nodeId);

                        logger.log(nodeId + ".log", INFO,
                            "Registration successful");

                        close(clientSock);
                        return;
                    }

                    /* ===================================================
                     *  NODE LOGIN FLOW (FR-03)
                     * =================================================== */
                    if (request.find("LOGIN") == 0) {

                        size_t first  = request.find('|');
                        size_t second = request.find('|', first + 1);

                        std::string nodeId =
                            request.substr(first + 1,
                            second - first - 1);

                        std::string pass =
                            request.substr(second + 1);

                        if (!registry.authenticate(nodeId, pass)) {

                            logger.log("engine.log", WARNING,
                                "Login failed for " + nodeId);

                            logger.log(nodeId + ".log", WARNING,
                                "Login failed");

                            NetworkUtil::sendPacket(
                                clientSock, "LOGIN_FAILED");

                            close(clientSock);
                            return;
                        }

                        /* Assign unique numeric identifier */
                        if (nodeNumericId.find(nodeId)
                            == nodeNumericId.end()) {

                            clientCounter++;
                            nodeNumericId[nodeId] = clientCounter;
                        }

                        int numericId =
                            nodeNumericId[nodeId];

                        logger.log("engine.log", INFO,
                            "Node-" + std::to_string(numericId)
                            + " connected");

                        logger.log(nodeId + ".log", INFO,
                            "Login successful");

                        /* ===================================================
                         *  SESSION MANAGEMENT (FR-04)
                         * =================================================== */
                        auto it = sessions.find(nodeId);

                        if (it != sessions.end())
                            it->second.restore();
                        else
                            sessions.emplace(nodeId,
                                Session("sess_" + nodeId,
                                nodeId));

                        socketToNode[clientSock] = nodeId;

                        /* Generate session encryption key (FR-10) */
                        std::string sessionKey =
                            CryptoUtil::generateKey();

                        sessionKeys[nodeId] = sessionKey;

                        NetworkUtil::sendPacket(
                            clientSock,
                            "LOGIN_SUCCESS|" + sessionKey
                        );

                        logger.log("engine.log", INFO,
                            "Session key generated for Node-"
                            + std::to_string(numericId));
                    }
                    else {
                        close(clientSock);
                        return;
                    }

                    /* ===================================================
                     *  MESSAGE PROCESSING & BROADCAST LOOP
                     *  (FR-05, FR-06, FR-10, FR-11)
                     * =================================================== */
                    while (true) {

                        std::string encryptedMsg =
                            NetworkUtil::receivePacket(clientSock);

                        if (encryptedMsg.empty())
                            break;

                        std::string sender =
                            socketToNode[clientSock];

                        std::string senderKey =
                            sessionKeys[sender];

                        /* Decrypt sender payload */
                        std::string decrypted =
                            CryptoUtil::decrypt(
                                encryptedMsg, senderKey);

                        logger.log(sender + ".log", DEBUG,
                            "Encrypted Sent: " + encryptedMsg);

                        logger.log(sender + ".log", DEBUG,
                            "Decrypted Sent: " + decrypted);

                        int numericId =
                            nodeNumericId[sender];

                        std::string finalMessage =
                            "Packet sent by Node-" +
                            std::to_string(numericId)
                            + ": " + decrypted;

                        /* ================= BROADCAST ================= */
                        for (auto& [nodeId, session] : sessions) {

                            if (session.isActive() &&
                                nodeId != sender &&
                                sessionKeys.find(nodeId)
                                != sessionKeys.end()) {

                                std::string receiverKey =
                                    sessionKeys[nodeId];

                                /* Re-encrypt for each receiver */
                                std::string reEncrypted =
                                    CryptoUtil::encrypt(
                                        finalMessage,
                                        receiverKey);

                                for (auto& [sock, mappedNode]
                                     : socketToNode) {

                                    if (mappedNode == nodeId) {

                                        NetworkUtil::sendPacket(
                                            sock, reEncrypted);

                                        logger.log(nodeId + ".log", DEBUG,
                                            "Encrypted Received: "
                                            + reEncrypted);

                                        logger.log(nodeId + ".log", DEBUG,
                                            "Decrypted Received: "
                                            + finalMessage);
                                    }
                                }
                            }
                        }
                    }

                    /* ===================================================
                     *  SESSION CLEANUP (FR-08)
                     * =================================================== */
                    std::string disconnectedNode = "UNKNOWN";

                    auto sockIt =
                        socketToNode.find(clientSock);

                    if (sockIt != socketToNode.end()) {

                        disconnectedNode =
                            sockIt->second;

                        sessionKeys.erase(disconnectedNode);

                        auto it =
                            sessions.find(disconnectedNode);

                        if (it != sessions.end())
                            it->second.invalidate();

                        socketToNode.erase(sockIt);
                    }

                    close(clientSock);

                    logger.log("engine.log", INFO,
                        "Client disconnected: "
                        + disconnectedNode);

                }
                catch (const std::exception& e) {
                    logger.log("engine.log", FATAL,
                        std::string("Thread exception: ")
                        + e.what());
                }
                catch (...) {
                    logger.log("engine.log", FATAL,
                        "Unknown exception in client thread");
                }

            }).detach();
        }
    }
    catch (const std::exception& e) {
        logger.log("engine.log", FATAL,
            std::string("Engine fatal exception: ")
            + e.what());
    }
    catch (...) {
        logger.log("engine.log", FATAL,
            "Unknown fatal exception in engine");
    }
}
