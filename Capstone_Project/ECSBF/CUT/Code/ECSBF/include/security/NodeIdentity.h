/**
 * @file NodeIdentity.h
 * @brief Defines the NodeIdentity class representing credentials and
 *        identification details of a provisioned ECSBF node.
 *
 * The NodeIdentity class encapsulates authentication-related
 * information required for node provisioning and verification
 * within the ECSBF framework.
 *
 * Architectural Context:
 * - Supports Node Provisioning (ECSBF_FR_02)
 * - Supports Mandatory Identity Verification (ECSBF_FR_03)
 * - Used by IdentityRegistry for authentication checks
 *
 * Each provisioned node in the ECSBF system is represented
 * by a NodeIdentity object containing its unique identifier
 * and associated credentials.
 *
 * @author Group 04
 * @version 1.0
 */

#ifndef NODE_IDENTITY_H
#define NODE_IDENTITY_H

#include <string>

/**
 * @class NodeIdentity
 * @brief Represents authentication credentials of an ECSBF node.
 *
 * This class stores:
 * - A unique node identifier
 * - The associated authentication credential (password)
 *
 * It acts as a data carrier object used by the
 * IdentityRegistry to validate access requests
 * during session establishment.
 */
class NodeIdentity {
private:

    /**
     * @brief Unique identifier assigned to the node.
     *
     * Used for session mapping, traceability,
     * and authentication within the ECSBF Engine.
     */
    std::string nodeId;

    /**
     * @brief Authentication credential for the node.
     *
     * Used during identity verification to ensure
     * that only authorized nodes can establish sessions.
     */
    std::string password;

public:

    /**
     * @brief Default constructor.
     *
     * Allows creation of an empty NodeIdentity instance.
     */
    NodeIdentity() = default;

    /**
     * @brief Constructs a NodeIdentity with credentials.
     *
     * Initializes the node identity with the specified
     * identifier and password.
     *
     * @param id Unique node identifier.
     * @param pass Authentication password.
     */
    NodeIdentity(const std::string& id, const std::string& pass);

    /**
     * @brief Retrieves the node identifier.
     *
     * @return The node ID string.
     */
    std::string getNodeId() const;

    /**
     * @brief Retrieves the node password.
     *
     * @return The stored password string.
     */
    std::string getPassword() const;
};

#endif
