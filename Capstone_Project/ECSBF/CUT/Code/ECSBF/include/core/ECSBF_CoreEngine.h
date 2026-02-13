/**
 * @file ECSBF_CoreEngine.h
 * @brief Defines the ECSBF_CoreEngine class — the centralized control unit
 *        of the Enterprise Concurrent Signal Broadcast Framework (ECSBF).
 *
 * The ECSBF_CoreEngine acts as the authoritative Engine component
 * responsible for:
 * - Accepting and managing node connections
 * - Maintaining persistent sessions (FR-04)
 * - Handling concurrent communication
 * - Mapping sockets to node identities
 * - Managing session encryption keys
 * - Interfacing with the Global Identity Registry (FR-07)
 *
 * Architectural Role:
 * This class represents the Core Engine described in the ECSBF SRS.
 * It orchestrates secure, concurrent, and traceable communication
 * between distributed endpoint nodes.
 *
 * Concurrency Model:
 * Thread-safe session and socket management is ensured using mutex
 * synchronization to prevent race conditions.
 *
 * @author Group 04
 * @version 1.0
 */

#pragma once

#include <mutex>
#include <unordered_map>
#include <string>

#include <registry/IdentityRegistry.h>
#include <Session.h>

/**
 * @class ECSBF_CoreEngine
 * @brief Centralized concurrency engine of the ECSBF framework.
 *
 * The ECSBF_CoreEngine is responsible for:
 * - Listening for incoming node connections
 * - Validating and managing active sessions
 * - Maintaining identity-to-session mappings
 * - Ensuring thread-safe access to shared resources
 * - Supporting encrypted communication sessions
 *
 * This class aligns with the Engine component described
 * in the ECSBF System Architecture (SRS Section 2.1).
 */
class ECSBF_CoreEngine {
private:

    /**
     * @brief Port number on which the Engine listens for connections.
     */
    int port;

    /**
     * @brief Server socket descriptor for accepting incoming connections.
     *
     * Represents the main listening socket bound to the configured port.
     */
    int serverSocket;

    /**
     * @brief Mutex used to ensure thread-safe access to shared resources.
     *
     * Protects session maps, socket mappings, and identity associations
     * from concurrent modification in a multi-threaded environment.
     */
    std::mutex engineMutex;

    /**
     * @brief Active persistent sessions (FR-04).
     *
     * Maps node identifiers to their corresponding Session objects.
     *
     * Key   : nodeId
     * Value : Session instance
     *
     * Ensures that verified nodes maintain persistent communication state.
     */
    std::unordered_map<std::string, Session> sessions;

    /**
     * @brief Mapping between socket descriptors and node identities.
     *
     * Key   : socket descriptor
     * Value : nodeId
     *
     * Enables reverse lookup from network-level connection
     * to logical node identity (traceability support).
     */
    std::unordered_map<int, std::string> socketToNode;

    /**
     * @brief Incremental counter used to assign numeric identifiers to nodes.
     *
     * Facilitates generation of unique numeric identifiers
     * for traceability and monitoring purposes.
     */
    int clientCounter = 0;

    /**
     * @brief Mapping of node identifiers to numeric IDs.
     *
     * Key   : nodeId
     * Value : Numeric identifier
     *
     * Supports identity resolution and tracking within the Engine.
     */
    std::unordered_map<std::string, int> nodeNumericId;

    /**
     * @brief Stores encryption session keys for active nodes.
     *
     * Key   : nodeId
     * Value : sessionKey
     *
     * Supports secure communication and cryptographic protection
     * as described in ECSBF_FR_10 and ECSBF_FR_11.
     */
    std::unordered_map<std::string, std::string> sessionKeys;

    /**
     * @brief Global Identity Registry instance.
     *
     * Responsible for verifying provisioned nodes before
     * allowing session establishment (FR-02, FR-03, FR-07).
     */
    IdentityRegistry registry;

public:

    /**
     * @brief Constructs the ECSBF Core Engine.
     *
     * Initializes the Engine to listen on the specified port.
     *
     * @param port Port number on which the Engine will accept connections.
     */
    ECSBF_CoreEngine(int port);

    /**
     * @brief Starts the ECSBF Engine.
     *
     * Initializes networking resources, begins listening
     * for incoming node connections, and activates the
     * concurrent session handling mechanism.
     *
     * This method represents the runtime entry point
     * for the Engine component.
     */
    void startEngine();
};
