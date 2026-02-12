#include <Session.h>

/*
 * ============================================================
 *  Module: ECSBF Session Management
 *  File  : Session.cpp
 * ------------------------------------------------------------
 *  Description:
 *  Provides the concrete implementation of the Session class,
 *  which models the lifecycle and state of a persistent
 *  session between an endpoint node and the ECSBF Core Engine.
 *
 *  This module supports FR-04 by allowing session state to
 *  survive transient disconnections and be restored upon
 *  successful re-authentication.
 * ============================================================
 */


/*
 * ============================================================
 *  Constructor
 * ============================================================
 *  Initializes a new session bound to a specific endpoint
 *  node.
 *
 *  Parameters:
 *   - sid : Unique session identifier
 *   - nid : Logical identifier of the endpoint node
 *
 *  Behavior:
 *   - Sessions are initialized in an active state by default
 * ============================================================
 */
Session::Session(const std::string& sid, const std::string& nid)
    : sessionId(sid), nodeId(nid), active(true) {}


/*
 * ============================================================
 *  Get Node Identifier
 * ============================================================
 *  Returns the logical node identifier associated with
 *  this session.
 *
 *  Const-qualified to guarantee read-only access.
 * ============================================================
 */
std::string Session::getNodeId() const {
    return nodeId;
}


/*
 * ============================================================
 *  Session State Query
 * ============================================================
 *  Indicates whether the session is currently active.
 *
 *  Returns:
 *   - true  if the session is active
 *   - false if the session has been invalidated
 * ============================================================
 */
bool Session::isActive() const {
    return active;
}


/*
 * ============================================================
 *  Invalidate Session
 * ============================================================
 *  Marks the session as inactive without destroying session
 *  metadata.
 *
 *  Intended Use:
 *   - Node disconnection
 *   - Temporary network failures
 *
 *  This enables session persistence across reconnects.
 * ============================================================
 */
void Session::invalidate() {
    active = false;
}


/*
 * ============================================================
 *  Restore Session (FR-04)
 * ============================================================
 *  Reactivates a previously invalidated session.
 *
 *  Intended Use:
 *   - Node re-authentication
 *   - Recovery after transient disconnections
 *
 *  This method directly fulfills FR-04 (Persistent Session
 *  Management) by preserving logical continuity.
 * ============================================================
 */
void Session::restore() {
    active = true;
}
