#ifndef CLIENT_H
#define CLIENT_H

/*
 * ============================================================
 *  File: Client.h
 *  Module: ECSBF Client Endpoint
 * ------------------------------------------------------------
 *  Description:
 *  This header defines the Client class, which represents an
 *  endpoint node within the Enterprise Concurrent Signal
 *  Broadcast Framework (ECSBF).
 *
 *  The Client is responsible for establishing a persistent
 *  socket-based connection with the ECSBF Core Engine,
 *  maintaining session-level communication, and asynchronously
 *  listening for broadcasted or point-to-point signals.
 *
 *  This component acts as a consumer within the distributed
 *  signal propagation architecture.
 *
 *  Design Considerations:
 *  - Encapsulation of socket and connection metadata
 *  - Separation of connection logic and packet reception
 *  - Support for concurrent signal listening
 *
 *  Note:
 *  This file contains interface declarations only.
 * ============================================================
 */

#include <string>

/*
 * ------------------------------------------------------------
 *  Class: Client
 * ------------------------------------------------------------
 *  Responsibility:
 *  Encapsulates all client-side networking responsibilities
 *  required to communicate with the ECSBF Core Engine.
 *
 *  The Client manages:
 *  - Socket lifecycle
 *  - Engine endpoint configuration
 *  - Background packet reception
 *
 *  This abstraction allows higher-level application logic
 *  to remain decoupled from low-level networking concerns.
 * ------------------------------------------------------------
 */
class Client {
private:
    /*
     * Socket file descriptor used for communication with
     * the ECSBF Core Engine.
     *
     * Lifecycle:
     *  - Initialized during connection
     *  - Used for both sending and receiving signals
     *  - Released during shutdown or failure
     */
    int sock;

    /*
     * IP address of the ECSBF Core Engine.
     * Stored as a string to allow flexibility for IPv4/IPv6
     * or DNS-based resolution.
     */
    std::string serverIp;
    std::string sessionKey;


    /*
     * Port number on which the ECSBF Core Engine is listening
     * for incoming client connections.
     */
    int serverPort;

    /*
     * Continuously listens for incoming packets or broadcast
     * signals from the ECSBF Core Engine.
     *
     * This method is intended to be executed in a dedicated
     * thread to ensure non-blocking reception and support
     * high-concurrency signal propagation.
     *
     * Visibility:
     *  - Private to prevent external misuse
     *  - Controlled internally by connection lifecycle
     */
    void listenForMessages();

public:
    /*
     * Constructor
     * --------------------------------------------------------
     * Initializes a Client instance with ECSBF Core Engine
     * connection parameters.
     *
     * Parameters:
     *  - ip   : Network address of the Core Engine
     *  - port : Listening port of the Core Engine
     *
     * Note:
     *  This constructor does not establish the connection.
     *  Actual network connection is deferred to connectToEngine().
     */
    Client(const std::string& ip, int port);

    /*
     * Establishes a network connection to the ECSBF Core Engine.
     *
     * Responsibilities:
     *  - Create and configure socket
     *  - Perform connection handshake
     *  - Initiate background packet listener
     *
     * This method represents the entry point for registering
     * the client into the ECSBF distributed communication
     * backbone.
     */
    void connectToEngine();
};

#endif
