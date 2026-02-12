#pragma once

/*
 * ============================================================
 *  File: Session.h
 *  Module: ECSBF Session Management
 * ------------------------------------------------------------
 *  Description:
 *  This header defines the Session class, which represents a
 *  persistent logical session between an endpoint node and
 *  the ECSBF Core Engine.
 *
 *  A Session encapsulates the lifecycle state of a connected
 *  node and enables the framework to maintain continuity
 *  across transient network disruptions.
 *
 *  This abstraction directly supports FR-04 (Persistent
 *  Session Management).
 * ============================================================
 */

#include <string>

/*
 * ------------------------------------------------------------
 *  Class: Session
 * ------------------------------------------------------------
 *  Responsibility:
 *  Models the session state associated with a single endpoint
 *  node registered with the ECSBF Core Engine.
 *
 *  The Session:
 *   - Binds a logical node identity to a session identifier
 *   - Tracks active/inactive connection state
 *   - Allows controlled invalidation and restoration
 *
 *  This class contains no networking logic and is intentionally
 *  lightweight to allow efficient storage and lookup within
 *  high-concurrency environments.
 * ------------------------------------------------------------
 */
class Session {
private:
    /*
     * Unique identifier assigned to this session.
     *
     * Used to distinguish between multiple logical sessions
     * across node reconnects or system restarts.
     */
    std::string sessionId;

    /*
     * Logical identifier of the endpoint node associated
     * with this session.
     */
    std::string nodeId;

    /*
     * Indicates whether the session is currently active.
     *
     * State:
     *  - true  : Session is valid and actively associated
     *            with a connected node
     *  - false : Session exists but is temporarily inactive
     */
    bool active;

public:
    /*
     * Constructor
     * --------------------------------------------------------
     * Creates a new session instance bound to a specific
     * endpoint node.
     *
     * Parameters:
     *  - sid : Unique session identifier
     *  - nid : Logical node identifier
     *
     * Note:
     *  Sessions are initialized in an active state unless
     *  explicitly invalidated.
     */
    Session(const std::string& sid, const std::string& nid);

    /*
     * Returns the logical node identifier associated with
     * this session.
     *
     * Const-correctness ensures read-only access.
     */
    std::string getNodeId() const;

    /*
     * Indicates whether the session is currently active.
     *
     * Returns:
     *  - true  if session is active
     *  - false if session has been invalidated
     */
    bool isActive() const;

    /*
     * Invalidates the session.
     *
     * Intended Use:
     *  - Node disconnection
     *  - Authentication failure
     *  - Controlled shutdown scenarios
     *
     * This operation does not destroy session metadata,
     * enabling potential restoration.
     */
    void invalidate();

    /*
     * Restores a previously invalidated session.
     *
     * Intended Use:
     *  - Node reconnection
     *  - Recovery after transient failures
     *
     * This method supports resilience by preserving
     * session continuity across network instability.
     */
    void restore();
};
