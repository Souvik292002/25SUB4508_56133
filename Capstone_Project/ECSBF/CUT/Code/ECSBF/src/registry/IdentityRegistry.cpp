/**
 * @file IdentityRegistry.cpp
 * @brief Implements the Global Identity Registry for ECSBF.
 *
 * This file provides the runtime implementation of the
 * IdentityRegistry class, which is responsible for:
 * - Registering provisioned nodes (FR-02)
 * - Authenticating login attempts (FR-03)
 * - Acting as the authoritative identity store (FR-07)
 *
 * Architectural Context:
 * The IdentityRegistry serves as the central authentication
 * authority used by the ECSBF Core Engine during session
 * establishment.
 */

#include <IdentityRegistry.h>

/**
 * ============================================================
 *  Register Node
 * ============================================================
 *
 * Adds a new NodeIdentity object to the internal registry.
 *
 * Behavior:
 * - Stores the node using its unique nodeId as the key
 * - Overwrites existing entry if nodeId already exists
 *
 * Alignment:
 * Supports Node Provisioning requirement (ECSBF_FR_02).
 */
void IdentityRegistry::registerNode(const NodeIdentity& node) {
    nodeDB[node.getNodeId()] = node;
}


/**
 * ============================================================
 *  Authenticate Node
 * ============================================================
 *
 * Validates whether the provided credentials match
 * a registered node entry.
 *
 * Process:
 * 1. Check if nodeId exists in registry
 * 2. Compare stored password with provided password
 *
 * Return Value:
 * - true  → Authentication successful
 * - false → Invalid nodeId or incorrect password
 *
 * Alignment:
 * Enforces Mandatory Identity Verification (ECSBF_FR_03).
 */
bool IdentityRegistry::authenticate(
    const std::string& nodeId,
    const std::string& password
) {
    auto it = nodeDB.find(nodeId);

    // Node does not exist in registry
    if (it == nodeDB.end())
        return false;

    // Validate stored credential
    return it->second.getPassword() == password;
}
