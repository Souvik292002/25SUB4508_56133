/**
 * @file Session.cpp
 * @brief Implements session lifecycle management for ECSBF.
 *
 * This file provides the runtime implementation of the Session class,
 * which is responsible for maintaining the logical communication state
 * between a node and the ECSBF Core Engine.
 *
 * Architectural Alignment:
 * - Supports Persistent Session Management (ECSBF_FR_04)
 * - Supports Controlled Session Termination (ECSBF_FR_08)
 *
 * The Session object represents a stateful association
 * between a verified node and the Engine.
 */

#include <Session.h>

/**
 * ============================================================
 *  Constructor
 * ============================================================
 *
 * Initializes a new session instance.
 *
 * Parameters:
 * - sid : Unique session identifier
 * - nid : Associated node identifier
 *
 * Behavior:
 * - Binds the session to a specific node
 * - Marks the session as active upon creation
 */
Session::Session(const std::string& sid, const std::string& nid)
    : sessionId(sid), nodeId(nid), active(true) {}


/**
 * ============================================================
 *  Get Node ID
 * ============================================================
 *
 * Retrieves the node identifier associated with this session.
 *
 * Returns:
 * - Node identifier string
 */
std::string Session::getNodeId() const {
    return nodeId;
}


/**
 * ============================================================
 *  Check Active State
 * ============================================================
 *
 * Indicates whether the session is currently active.
 *
 * Returns:
 * - true  → Session is active
 * - false → Session has been invalidated
 */
bool Session::isActive() const {
    return active;
}


/**
 * ============================================================
 *  Invalidate Session
 * ============================================================
 *
 * Marks the session as inactive.
 *
 * Typically invoked when:
 * - A node disconnects
 * - Session timeout occurs
 * - Cleanup process is triggered
 */
void Session::invalidate() {
    active = false;
}


/**
 * ============================================================
 *  Restore Session
 * ============================================================
 *
 * Restores a previously invalidated session
 * to active state.
 *
 * Supports resilience against transient
 * network interruptions.
 */
void Session::restore() {
    active = true;
}
