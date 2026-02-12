#include <ECSBF_CoreEngine.h>
#include <Logger.h>
#include <NetworkUtil.h>

#include <unistd.h>
#include <arpa/inet.h>
#include <thread>
#include <CryptoUtil.h>
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
 */
void ECSBF_CoreEngine::startEngine() {

    Logger::info("Starting ECSBF Engine...");

    /* --------------------------------------------------------
     *  Server Socket Initialization
     * -------------------------------------------------------- */
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in serverAddr{};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(port);

    bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr));
    listen(serverSocket, 5);

    Logger::info("ECSBF Engine listening on port " + std::to_string(port));

    /* --------------------------------------------------------
     *  Accept Loop
     * -------------------------------------------------------- */
    while (true) {

        int clientSock = accept(serverSocket, nullptr, nullptr);

        std::thread([this, clientSock]() {

           


            std::string request = NetworkUtil::receivePacket(clientSock);

            /* =================================================
             *  REGISTRATION WORKFLOW
             * ================================================= */
            if (request.find("REGISTER") == 0) {

                size_t first  = request.find('|');
                size_t second = request.find('|', first + 1);

                std::string nodeId = request.substr(first + 1, second - first - 1);
                std::string pass   = request.substr(second + 1);

                registry.registerNode(NodeIdentity(nodeId, pass));
                NetworkUtil::sendPacket(clientSock, "REGISTER_SUCCESS");

                close(clientSock);
                return;
            }

            /* =================================================
             *  LOGIN WORKFLOW
             * ================================================= */
            if (request.find("LOGIN") == 0) {

    size_t first  = request.find('|');
    size_t second = request.find('|', first + 1);

    std::string nodeId = request.substr(first + 1, second - first - 1);
    std::string pass   = request.substr(second + 1);

    /* ---------- Credential Validation ---------- */
    if (!registry.authenticate(nodeId, pass)) {
        NetworkUtil::sendPacket(clientSock, "LOGIN_FAILED");
        close(clientSock);
        return;
    }

    /* -------------------------------------------
     *  Assign Numeric Node ID (Node-1, Node-2...)
     * ------------------------------------------- */
    if (nodeNumericId.find(nodeId) == nodeNumericId.end()) {
        clientCounter++;
        nodeNumericId[nodeId] = clientCounter;
    }

    int numericId = nodeNumericId[nodeId];

    Logger::info("Node-" + std::to_string(numericId) + " connected");

    /* -------------------------------------------
     *  FR-04: Persistent Session Restore / Create
     * ------------------------------------------- */
    auto it = sessions.find(nodeId);

    if (it != sessions.end()) {
        it->second.restore();
        Logger::info("Restoring existing session for Node-" + std::to_string(numericId));
    } else {
        sessions.emplace(nodeId, Session("sess_" + nodeId, nodeId));
        Logger::info("Creating new session for Node-" + std::to_string(numericId));
    }

    socketToNode[clientSock] = nodeId;
   /* Generate session key ONCE */
std::string sessionKey = CryptoUtil::generateKey();

/* Store key for this node */
sessionKeys[nodeId] = sessionKey;

/* Send key to client */
NetworkUtil::sendPacket(
    clientSock,
    "LOGIN_SUCCESS|" + sessionKey
);

}

            else {
                close(clientSock);
                return;
            }

            /* =================================================
 *  MESSAGE BROADCAST LOOP (WITH ENCRYPTION)
 * ================================================= */
while (true) {

    std::string encryptedMsg =
        NetworkUtil::receivePacket(clientSock);

    if (encryptedMsg.empty())
        break;

    auto sockIt = socketToNode.find(clientSock);
    if (sockIt == socketToNode.end())
        break;

    std::string sender = sockIt->second;
    int numericId = nodeNumericId[sender];

    /* ----------------------------------------
     *  Decrypt using global key
     * ---------------------------------------- */
    /* Get sender's session key */
std::string senderKey = sessionKeys[sender];

/* Decrypt using sender key */
std::string decrypted =
    CryptoUtil::decrypt(encryptedMsg, senderKey);


    /* ----------------------------------------
     *  Create broadcast message
     * ---------------------------------------- */
    std::string finalMessage =
        "Packet sent by Node-" +
        std::to_string(numericId) +
        ": " + decrypted;

    /* ----------------------------------------
     *  Log for sender
     * ---------------------------------------- */
    Logger::logToNode(sender, "Encrypted: " + encryptedMsg);
    Logger::logToNode(sender, "Decrypted: " + decrypted);

    /* ----------------------------------------
     *  Broadcast to other active sessions
     * ---------------------------------------- */
    for (auto& [nodeId, session] : sessions) {

        if (session.isActive() && nodeId != sender) {

            /* Get receiver key */
std::string receiverKey = sessionKeys[nodeId];

/* Re-encrypt for receiver */
std::string reEncrypted =
    CryptoUtil::encrypt(finalMessage, receiverKey);


            for (auto& [sock, mappedNode] : socketToNode) {

                if (mappedNode == nodeId) {

                    NetworkUtil::sendPacket(sock, reEncrypted);

                    /* Log for receiver */
                    Logger::logToNode(nodeId,
                        "Received: " + finalMessage);
                }
            }
        }
    }
}

            /* =================================================
             *  CONNECTION CLEANUP
             * ================================================= */
            auto sockIt = socketToNode.find(clientSock);

if (sockIt != socketToNode.end()) {

    std::string nodeId = sockIt->second;
    int numericId = nodeNumericId[nodeId];

    auto sessIt = sessions.find(nodeId);
    if (sessIt != sessions.end()) {
        sessIt->second.invalidate();
    }

    socketToNode.erase(sockIt);

    Logger::info("Node-" + std::to_string(numericId) + " disconnected");
}
else {
    Logger::info("Node disconnected");
}


        }).detach();
    }
}
