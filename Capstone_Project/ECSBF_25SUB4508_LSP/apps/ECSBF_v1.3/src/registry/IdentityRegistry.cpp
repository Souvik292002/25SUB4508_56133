#include <IdentityRegistry.h>

/*
 * ============================================================
 *  Module: ECSBF Identity & Access Management
 *  File  : IdentityRegistry.cpp
 * ------------------------------------------------------------
 *  Description:
 *  Provides the concrete implementation of the IdentityRegistry
 *  component used by the ECSBF Core Engine to manage endpoint
 *  node identities and authenticate incoming connections.
 *
 *  This module enforces identity-based access control by
 *  validating node credentials prior to session establishment.
 *
 *  The implementation is intentionally simple and in-memory,
 *  allowing focus on architectural clarity rather than
 *  persistence or external identity providers.
 * ============================================================
 */


/*
 * ============================================================
 *  Register Node
 * ============================================================
 *  Adds a new endpoint node identity to the in-memory registry.
 *
 *  Parameters:
 *   - node : NodeIdentity object containing identity metadata
 *
 *  Behavior:
 *   - Stores or overwrites the identity entry keyed by nodeId
 *
 *  Intended Use:
 *   - Administrative provisioning
 *   - Initial node onboarding
 * ============================================================
 */
void IdentityRegistry::registerNode(const NodeIdentity& node) {
    nodeDB[node.getNodeId()] = node;
}


/*
 * ============================================================
 *  Authenticate Node
 * ============================================================
 *  Validates the credentials of an endpoint node attempting
 *  to establish or restore a session with the ECSBF Core Engine.
 *
 *  Parameters:
 *   - nodeId   : Logical identifier of the endpoint node
 *   - password : Authentication secret provided by the node
 *
 *  Returns:
 *   - true  if the supplied credentials are valid
 *   - false if the node does not exist or credentials mismatch
 *
 *  Behavior:
 *   - Performs a lookup in the in-memory identity store
 *   - Compares supplied credentials against stored metadata
 * ============================================================
 */
bool IdentityRegistry::authenticate(
    const std::string& nodeId,
    const std::string& password
) {
    auto it = nodeDB.find(nodeId);
    if (it == nodeDB.end())
        return false;

    return it->second.getPassword() == password;
}
