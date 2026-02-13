/**
 * @file NodeIdentity.cpp
 * @brief Implements the NodeIdentity data model for ECSBF.
 *
 * This file provides the implementation of the NodeIdentity class,
 * which encapsulates:
 * - Unique node identifier
 * - Associated authentication credential
 *
 * Architectural Alignment:
 * - Supports Node Provisioning (ECSBF_FR_02)
 * - Supports Mandatory Identity Verification (ECSBF_FR_03)
 *
 * The NodeIdentity object acts as a lightweight data carrier
 * used by the IdentityRegistry for authentication enforcement.
 */

#include <NodeIdentity.h>

/**
 * ============================================================
 *  Parameterized Constructor
 * ============================================================
 *
 * Initializes a NodeIdentity instance with the provided
 * node identifier and password.
 *
 * Parameters:
 * - id   : Unique identifier of the node
 * - pass : Authentication credential
 *
 * This constructor is typically invoked during
 * node registration within the Engine.
 */
NodeIdentity::NodeIdentity(const std::string& id,
                           const std::string& pass)
    : nodeId(id), password(pass) {}


/**
 * ============================================================
 *  Get Node ID
 * ============================================================
 *
 * Retrieves the unique identifier associated with this node.
 *
 * Returns:
 * - Node identifier string
 */
std::string NodeIdentity::getNodeId() const {
    return nodeId;
}


/**
 * ============================================================
 *  Get Password
 * ============================================================
 *
 * Retrieves the stored authentication credential.
 *
 * Security Note:
 * In a production system, passwords should be stored
 * in hashed form rather than plaintext.
 *
 * Returns:
 * - Stored password string
 */
std::string NodeIdentity::getPassword() const {
    return password;
}
