#pragma once

/*
 * ============================================================
 *  File: IdentityRegistry.h
 *  Module: ECSBF Identity & Access Management
 * ------------------------------------------------------------
 *  Description:
 *  This header defines the IdentityRegistry class, which serves
 *  as the authoritative in-memory identity store for endpoint
 *  nodes participating in the Enterprise Concurrent Signal
 *  Broadcast Framework (ECSBF).
 *
 *  The Identity Registry is responsible for maintaining node
 *  identity records and validating authentication credentials
 *  during connection and session establishment.
 *
 *  This component enforces trust boundaries within the ECSBF
 *  architecture and ensures that only authorized nodes are
 *  permitted to participate in signal propagation.
 * ============================================================
 */

#include <unordered_map>
#include <string>
#include "NodeIdentity.h"

/*
 * ------------------------------------------------------------
 *  Class: IdentityRegistry
 * ------------------------------------------------------------
 *  Responsibility:
 *  Manages registration and authentication of endpoint node
 *  identities within the ECSBF ecosystem.
 *
 *  The registry:
 *   - Stores node identity metadata
 *   - Provides credential validation services
 *   - Acts as a security gatekeeper for the Core Engine
 *
 *  This abstraction allows authentication logic to remain
 *  decoupled from networking and session management concerns.
 * ------------------------------------------------------------
 */
class IdentityRegistry {
private:
    /*
     * In-memory database of registered node identities.
     *
     * Key:
     *  - nodeId : Unique logical identifier of the endpoint node
     *
     * Value:
     *  - NodeIdentity object containing authentication metadata
     *
     * This structure enables efficient lookup during connection
     * and authentication workflows.
     */
    std::unordered_map<std::string, NodeIdentity> nodeDB;

public:
    /*
     * Registers a new endpoint node in the identity registry.
     *
     * Parameters:
     *  - node : NodeIdentity object containing registration data
     *
     * Intended Use:
     *  - Administrative provisioning
     *  - Initial node onboarding
     *
     * Note:
     *  This method does not establish a network session; it
     *  merely records identity information for future use.
     */
    void registerNode(const NodeIdentity& node);

    /*
     * Authenticates an endpoint node using supplied credentials.
     *
     * Parameters:
     *  - nodeId   : Logical identifier of the node
     *  - password : Authentication secret provided by the node
     *
     * Returns:
     *  - true  if credentials are valid
     *  - false if authentication fails
     *
     * Intended Use:
     *  - Connection-time authentication
     *  - Session restoration validation
     */
    bool authenticate(const std::string& nodeId, const std::string& password);
};
