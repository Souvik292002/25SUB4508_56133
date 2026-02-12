#include "ECSBF_CoreEngine.h"
#include "Logger.h"
#include "NetworkUtil.h"

#include <unistd.h>
#include <arpa/inet.h>
#include <thread>

/*
 * ============================================================
 *  ECSBF_CoreEngine Constructor
 * ============================================================
 *  Initializes the Core Engine with the configured listening
 *  port.
 *
 *  Note:
 *  - Socket creation and binding are deferred to startEngine()
 *    to allow controlled startup sequencing.
 * ============================================================
 */
ECSBF_CoreEngine::ECSBF_CoreEngine(int port)
    : port(port) {}


/*
 * ============================================================
 *  Start ECSBF Core Engine
 * ============================================================
 *  Bootstraps the ECSBF Core Engine and enters the main accept
 *  loop.
 *
 *  Responsibilities:
 *   - Initialize server socket
 *   - Bind and listen on configured port
 *   - Accept concurrent node connections
 *   - Delegate each node to a dedicated handler thread
 *
 *  This method represents the primary execution entry point
 *  for the ECSBF communication backbone.
 * ============================================================
 */
void ECSBF_CoreEngine::startEngine() {
    Logger::info("Starting ECSBF Engine...");

    /*
     * --------------------------------------------------------
     *  Server Socket Initialization
     * --------------------------------------------------------
     */
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in serverAddr{};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(port);

    bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr));
    listen(serverSocket, 5);

    Logger::info("ECSBF Engine listening on port " + std::to_string(port));

    /*
     * --------------------------------------------------------
     *  Accept Loop
     * --------------------------------------------------------
     *  Continuously accepts incoming endpoint node connections.
     *  Each connection is handled in its own detached thread
     *  to support high concurrency.
     * --------------------------------------------------------
     */
    while (true) {
        int clientSock = accept(serverSocket, nullptr, nullptr);

        /*
         * Spawn a dedicated handler thread for the connected
         * endpoint node.
         */
        std::thread([this, clientSock]() {

            Logger::info("Node connected to ECSBF Engine");

            /*
             * ------------------------------------------------
             *  Initial Handshake Request
             * ------------------------------------------------
             *  First message determines whether the node is
             *  requesting registration or authentication.
             * ------------------------------------------------
             */
            std::string request = NetworkUtil::receivePacket(clientSock);

            /* =================================================
             *  Registration Workflow
             * =================================================
             *  Handles initial provisioning of a new endpoint
             *  node into the Identity Registry.
             * =================================================
             */
            if (request.find("REGISTER") == 0) {

                size_t first  = request.find('|');
                size_t second = request.find('|', first + 1);

                std::string nodeId = request.substr(first + 1, second - first - 1);
                std::string pass   = request.substr(second + 1);

                registry.registerNode(NodeIdentity(nodeId, pass));
                NetworkUtil::sendPacket(clientSock, "REGISTER_SUCCESS");

                /*
                 * Registration is a one-time operation;
                 * connection is closed after completion.
                 */
                close(clientSock);
                return;
            }

            /* =================================================
             *  Authentication Workflow
             * =================================================
             *  Validates node credentials and establishes or
             *  restores a persistent session upon success.
             * =================================================
             */
            if (request.find("LOGIN") == 0) {

                size_t first  = request.find('|');
                size_t second = request.find('|', first + 1);

                std::string nodeId = request.substr(first + 1, second - first - 1);
                std::string pass   = request.substr(second + 1);

                /*
                 * Credential validation via Identity Registry.
                 */
                if (!registry.authenticate(nodeId, pass)) {
                    NetworkUtil::sendPacket(clientSock, "LOGIN_FAILED");
                    close(clientSock);
                    return;
                }

                /* ---------------------------------------------
                 *  FR-04: Persistent Session Restore / Create
                 * ---------------------------------------------
                 *  Restores an existing session if present;
                 *  otherwise creates a new session.
                 * ---------------------------------------------
                 */
                auto it = sessions.find(nodeId);
                if (it != sessions.end()) {
                    it->second.restore();
                    Logger::info("Restoring existing session for node " + nodeId);
                } else {
                    sessions.emplace(nodeId, Session("sess_" + nodeId, nodeId));
                    Logger::info("Creating new session for node " + nodeId);
                }

                /*
                 * Map socket descriptor to logical node identity
                 * for efficient reverse lookup during messaging.
                 */
                socketToNode[clientSock] = nodeId;
                NetworkUtil::sendPacket(clientSock, "LOGIN_SUCCESS");
            }
            else {
                /*
                 * Invalid or malformed initial request.
                 */
                close(clientSock);
                return;
            }

            /* =================================================
             *  Message Broadcast Loop
             * =================================================
             *  Receives packet from the connected node and
             *  broadcasts them to all other active sessions.
             *
             *  This loop implements the core signal propagation
             *  behavior of ECSBF.
             * =================================================
             */
            while (true) {
                std::string msg = NetworkUtil::receivePacket(clientSock);
                if (msg.empty())
                    break;

                auto sockIt = socketToNode.find(clientSock);
                if (sockIt == socketToNode.end())
                    break;

                std::string sender = sockIt->second;

                /*
                 * Broadcast message to all active sessions
                 * except the sender.
                 */
                for (auto& [nodeId, session] : sessions) {
                    if (session.isActive() && nodeId != sender) {
                        for (auto& [sock, mappedNode] : socketToNode) {
                            if (mappedNode == nodeId) {
                                NetworkUtil::sendPacket(
                                    sock,
                                    "Packet sent by " + sender + ": " + msg
                                );
                            }
                        }
                    }
                }
            }

            /* =================================================
             *  Connection Cleanup
             * =================================================
             *  Marks the session as inactive while preserving
             *  session state for future restoration.
             * =================================================
             */
            auto sockIt = socketToNode.find(clientSock);
            if (sockIt != socketToNode.end()) {
                std::string nodeId = sockIt->second;

                auto sessIt = sessions.find(nodeId);
                if (sessIt != sessions.end()) {
                    sessIt->second.invalidate();   // FR-04: session persists
                }

                socketToNode.erase(sockIt);
            }

            close(clientSock);
            Logger::info("Node disconnected");

        }).detach();
    }
}
