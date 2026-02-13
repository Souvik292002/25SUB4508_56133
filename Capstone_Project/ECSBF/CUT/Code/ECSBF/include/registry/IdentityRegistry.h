/**
 * @file IdentityRegistry.h
 * @brief Defines the IdentityRegistry class responsible for managing
 *        provisioned node identities within the ECSBF framework.
 *
 * The IdentityRegistry serves as the authoritative repository for
 * all registered endpoint nodes in the system.
 *
 * Architectural Context:
 * - Implements Global Identity Registry (ECSBF_FR_07)
 * - Enforces node provisioning requirements (ECSBF_FR_02)
 * - Supports mandatory authentication checks (ECSBF_FR_03)
 *
 * This component ensures that only authorized and provisioned nodes
 * can establish sessions with the ECSBF Core Engine.
 *
 * @author Group 04
 * @version 1.0
 */

#pragma once

#include <unordered_map>
#include <string>
#include <NodeIdentity.h>

/**
 * @class IdentityRegistry
 * @brief Manages registered node identities and authentication.
 *
 * The IdentityRegistry maintains a persistent in-memory
 * mapping of node identifiers to their corresponding
 * identity credentials.
 *
 * Responsibilities:
 * - Registering new nodes into the system
 * - Verifying authentication credentials
 * - Acting as the central authority for identity validation
 *
 * This class is utilized by the ECSBF_CoreEngine during
 * session establishment and identity verification.
 */
class IdentityRegistry {
private:

    /**
     * @brief Internal database of registered nodes.
     *
     * Key   : nodeId
     * Value : NodeIdentity object containing credentials and metadata
     *
     * Represents the Global Identity Registry described in the ECSBF SRS.
     */
    std::unordered_map<std::string, NodeIdentity> nodeDB;

public:

    /**
     * @brief Registers a new node in the Identity Registry.
     *
     * Adds the provided NodeIdentity instance to the internal
     * node database, making it eligible for authentication.
     *
     * @param node NodeIdentity object representing the provisioned node.
     */
    void registerNode(const NodeIdentity& node);

    /**
     * @brief Authenticates a node using its credentials.
     *
     * Validates whether the provided nodeId exists and whether
     * the supplied password matches the stored credentials.
     *
     * @param nodeId Unique identifier of the node.
     * @param password Authentication credential.
     * @return true if authentication succeeds; otherwise false.
     */
    bool authenticate(const std::string& nodeId, const std::string& password);
};
