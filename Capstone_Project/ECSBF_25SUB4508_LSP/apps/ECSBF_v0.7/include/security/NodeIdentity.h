#ifndef NODE_IDENTITY_H
#define NODE_IDENTITY_H

/*
 * ============================================================
 *  File: NodeIdentity.h
 *  Module: ECSBF Identity Model
 * ------------------------------------------------------------
 *  Description:
 *  This header defines the NodeIdentity class, which represents
 *  the credential-bearing identity of an endpoint node within
 *  the Enterprise Concurrent Signal Broadcast Framework (ECSBF).
 *
 *  A NodeIdentity encapsulates authentication information used
 *  by the IdentityRegistry to validate nodes attempting to
 *  connect to the ECSBF Core Engine.
 *
 *  This class acts as a lightweight data model and does not
 *  perform authentication or authorization logic itself.
 * ============================================================
 */

#include <string>

/*
 * ------------------------------------------------------------
 *  Class: NodeIdentity
 * ------------------------------------------------------------
 *  Responsibility:
 *  Represents the logical identity and authentication secret
 *  associated with a single ECSBF endpoint node.
 *
 *  The NodeIdentity:
 *   - Stores node identifiers
 *   - Stores authentication credentials
 *   - Provides read-only accessors for validation workflows
 *
 *  This abstraction supports separation of concerns by
 *  isolating identity data from authentication logic.
 * ------------------------------------------------------------
 */
class NodeIdentity {
private:
    /*
     * Unique logical identifier assigned to the endpoint node.
     *
     * Used as the primary key for identity lookup within the
     * IdentityRegistry and for session association.
     */
    std::string nodeId;

    /*
     * Authentication secret associated with the node identity.
     *
     * This value is validated during authentication but is
     * never interpreted or processed by this class itself.
     */
    std::string password;

public:
    /*
     * Default constructor.
     *
     * Provided to support container usage and deferred
     * initialization scenarios.
     */
    NodeIdentity() = default;

    /*
     * Parameterized constructor.
     *
     * Initializes a NodeIdentity with the supplied credentials.
     *
     * Parameters:
     *  - id   : Logical node identifier
     *  - pass : Authentication secret
     */
    NodeIdentity(const std::string& id, const std::string& pass);

    /*
     * Returns the logical node identifier.
     *
     * Const-qualified to guarantee read-only access.
     */
    std::string getNodeId() const;

    /*
     * Returns the authentication secret associated with
     * this node identity.
     *
     * Note:
     *  Access to this value should be limited to trusted
     *  authentication workflows.
     */
    std::string getPassword() const;
};

#endif
