/**
 * @file Client.h
 * @brief Defines the Client class for ECSBF endpoint communication.
 *
 * This header declares the Client class responsible for establishing
 * and maintaining a connection with the ECSBF Core Engine.
 *
 * The Client acts as an Endpoint Node component within the ECSBF
 * architecture. It manages socket-based communication, session
 * identification, and incoming signal listening from the Engine.
 *
 * The class encapsulates connection handling and message reception
 * while preserving abstraction from underlying networking details.
 *
 * Architecture Context:
 * - Acts as an ECSBF Endpoint Node
 * - Connects to centralized Engine via TCP/IP
 * - Participates in persistent session communication
 *
 * @author Group 04
 * @version 1.0
 */

#ifndef CLIENT_H
#define CLIENT_H

#include <string>

/**
 * @class Client
 * @brief Represents an ECSBF endpoint node client.
 *
 * The Client class is responsible for:
 * - Establishing a connection to the ECSBF Core Engine
 * - Managing the client-side socket descriptor
 * - Maintaining session identification
 * - Listening for broadcasted signals from the Engine
 *
 * This class follows a persistent session model where,
 * after successful connection, it continuously listens
 * for incoming broadcast messages.
 */
class Client {
private:

    /**
     * @brief Socket descriptor used for TCP communication.
     *
     * Represents the active socket connection between
     * this client and the ECSBF Engine.
     */
    int sock;

    /**
     * @brief IP address of the ECSBF Engine.
     *
     * Stores the server's IPv4/IPv6 address used
     * to establish the connection.
     */
    std::string serverIp;

    /**
     * @brief Unique session identifier assigned after handshake.
     *
     * Maintains session-level identification for
     * traceability and authentication.
     */
    std::string sessionKey;

    /**
     * @brief Port number of the ECSBF Engine.
     *
     * Specifies the server-side port used
     * for establishing TCP connection.
     */
    int serverPort;

    /**
     * @brief Listens for incoming broadcast messages from the Engine.
     *
     * This method continuously monitors the active socket
     * connection for incoming signals dispatched by the Engine.
     *
     * It is expected to operate as part of a persistent
     * communication session.
     */
    void listenForMessages();

public:

    /**
     * @brief Constructs a Client instance.
     *
     * Initializes the client with the specified server IP
     * address and port number required for connection.
     *
     * @param ip The IP address of the ECSBF Engine.
     * @param port The port number on which the Engine is listening.
     */
    Client(const std::string& ip, int port);

    /**
     * @brief Establishes connection with the ECSBF Engine.
     *
     * Performs the client-side connection procedure,
     * including socket initialization and session establishment.
     *
     * Upon successful connection, the client becomes an
     * active participant in the ECSBF signal broadcast framework.
     */
    void connectToEngine();
};

#endif
