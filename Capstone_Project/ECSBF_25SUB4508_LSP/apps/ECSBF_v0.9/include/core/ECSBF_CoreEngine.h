#pragma once

/*
 * ============================================================
 *  File: ECSBF_CoreEngine.h
 *  Module: ECSBF Core Engine
 * ------------------------------------------------------------
 *  Description:
 *  This header defines the ECSBF_CoreEngine class, which serves
 *  as the centralized coordination and control unit within the
 *  Enterprise Concurrent Signal Broadcast Framework (ECSBF).
 *
 *  The Core Engine is responsible for:
 *   - Accepting and managing concurrent node connections
 *   - Maintaining persistent session state (FR-04)
 *   - Mapping network sockets to authenticated node identities
 *   - Enforcing identity verification via the Identity Registry
 *
 *  This component forms the backbone of the ECSBF architecture
 *  and acts as the authoritative signal distribution hub.
 *
 *  Design Goals:
 *   - High concurrency
 *   - Strong session persistence
 *   - Centralized identity governance
 *   - Clean separation of networking and identity concerns
 * ============================================================
 */

#include <unordered_map>
#include <string>

#include <registry/IdentityRegistry.h>
#include <Session.h>

/*
 * ------------------------------------------------------------
 *  Class: ECSBF_CoreEngine
 * ------------------------------------------------------------
 *  Responsibility:
 *  Implements the central server-side engine that orchestrates
 *  all node interactions within the ECSBF ecosystem.
 *
 *  The Core Engine:
 *   - Listens on a predefined port for incoming node requests
 *   - Tracks active sessions across the distributed network
 *   - Associates network sockets with logical node identities
 *   - Acts as the enforcement point for authentication and
 *     authorization policies
 *
 *  This abstraction ensures scalability and resilience by
 *  centralizing critical coordination logic.
 * ------------------------------------------------------------
 */
class ECSBF_CoreEngine {
private:
    /*
     * TCP port on which the ECSBF Core Engine listens for
     * incoming endpoint node connections.
     */
    int port;

    /*
     * Server-side socket descriptor used to accept and manage
     * concurrent client connections.
     *
     * Lifecycle:
     *  - Initialized during engine startup
     *  - Bound to the configured port
     *  - Used to accept incoming node sockets
     */
    int serverSocket;

    /*
     * --------------------------------------------------------
     *  FR-04: Persistent Session Management
     * --------------------------------------------------------
     *  Maintains active session state for all authenticated
     *  endpoint nodes.
     *
     *  Keyed by:
     *   - nodeId : Logical identity of the connected endpoint
     *
     *  Value:
     *   - Session object encapsulating session-specific state
     *
     *  This structure enables:
     *   - Session recovery
     *   - State-aware signal routing
     *   - Controlled disconnection handling
     */
    std::unordered_map<std::string, Session> sessions;   // nodeId -> Session

    /*
     * Reverse lookup mapping between socket descriptors and
     * logical node identifiers.
     *
     * Purpose:
     *  - Enables efficient resolution of node identity from
     *    low-level network events
     *  - Supports rapid session lookup during I/O operations
     */
    std::unordered_map<int, std::string> socketToNode;   // socket -> nodeId
/*Assign a numeric ID when client logs in

Store it in engine

Use that ID instead of username while broadcasting */

std::unordered_map<std::string, std::string> sessionKeys;

    int clientCounter = 0;
std::unordered_map<std::string, int> nodeNumericId;

    /*
     * Identity Registry instance responsible for validating
     * and managing endpoint node identities.
     *
     * This component enforces trust boundaries by ensuring
     * that only registered and authenticated nodes are
     * permitted to establish persistent sessions.
     */
    IdentityRegistry registry;

public:
    /*
     * Constructor
     * --------------------------------------------------------
     * Initializes the ECSBF Core Engine with the specified
     * listening port.
     *
     * Parameters:
     *  - port : Network port for accepting node connections
     *
     * Note:
     *  Resource allocation and socket binding are deferred
     *  to startEngine() to allow controlled startup sequencing.
     */
    ECSBF_CoreEngine(int port);

    /*
     * Starts the ECSBF Core Engine.
     *
     * Responsibilities:
     *  - Initialize and bind the server socket
     *  - Enter accept loop for incoming node connections
     *  - Spawn or delegate connection handlers
     *
     * This method represents the primary execution entry
     * point for the ECSBF communication backbone.
     */
    void startEngine();
};
