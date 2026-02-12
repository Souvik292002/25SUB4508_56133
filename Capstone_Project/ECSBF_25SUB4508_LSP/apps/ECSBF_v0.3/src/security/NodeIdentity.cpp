#include "NodeIdentity.h"

/*
 * ============================================================
 *  Module: ECSBF Identity Model
 *  File  : NodeIdentity.cpp
 * ------------------------------------------------------------
 *  Description:
 *  Provides the concrete implementation of the NodeIdentity
 *  data model used within the Enterprise Concurrent Signal
 *  Broadcast Framework (ECSBF).
 *
 *  This module encapsulates identity credential storage and
 *  exposes read-only accessors for authentication workflows.
 *
 *  The implementation is intentionally minimal to maintain
 *  clarity and separation of concerns.
 * ============================================================
 */


/*
 * ============================================================
 *  Parameterized Constructor
 * ============================================================
 *  Initializes a NodeIdentity instance with the provided
 *  credentials.
 *
 *  Parameters:
 *   - id   : Logical identifier of the endpoint node
 *   - pass : Authentication secret associated with the node
 *
 *  Note:
 *   - No validation is performed at this layer; validation
 *     responsibilities are delegated to the IdentityRegistry.
 * ============================================================
 */
NodeIdentity::NodeIdentity(const std::string& id,
                           const std::string& pass)
    : nodeId(id), password(pass) {}


/*
 * ============================================================
 *  Get Node Identifier
 * ============================================================
 *  Returns the logical identifier associated with this
 *  endpoint node.
 *
 *  Const-qualified to guarantee read-only access.
 * ============================================================
 */
std::string NodeIdentity::getNodeId() const {
    return nodeId;
}


/*
 * ============================================================
 *  Get Authentication Secret
 * ============================================================
 *  Returns the authentication secret associated with this
 *  node identity.
 *
 *  Note:
 *   - Access to this value should be limited to trusted
 *     authentication workflows only.
 * ============================================================
 */
std::string NodeIdentity::getPassword() const {
    return password;
}
