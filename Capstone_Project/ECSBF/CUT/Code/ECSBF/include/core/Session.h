/**
 * @file Session.h
 * @brief Defines the Session class representing a persistent communication
 *        session between an endpoint node and the ECSBF Core Engine.
 *
 * The Session class encapsulates session-level state management
 * for connected nodes within the ECSBF framework.
 *
 * Architectural Context:
 * - Supports Persistent Session Management (ECSBF_FR_04)
 * - Maintains logical identity binding between node and session
 * - Enables controlled session invalidation and restoration
 *
 * Each active node connected to the Engine is associated with
 * a Session object that tracks its lifecycle state.
 *
 * @author Group 04
 * @version 1.0
 */

#pragma once

#include <string>

/**
 * @class Session
 * @brief Represents a persistent session between a node and the Engine.
 *
 * The Session class is responsible for:
 * - Binding a session identifier to a node identifier
 * - Maintaining active/inactive session state
 * - Supporting controlled invalidation
 * - Allowing restoration after temporary disruptions
 *
 * This aligns with ECSBF's requirement for persistent,
 * fault-tolerant communication sessions.
 */
class Session {
private:

    /**
     * @brief Unique identifier for this session.
     *
     * Distinguishes one session instance from another
     * within the ECSBF Engine.
     */
    std::string sessionId;

    /**
     * @brief Identifier of the node associated with this session.
     *
     * Links session state to a provisioned node identity.
     */
    std::string nodeId;

    /**
     * @brief Indicates whether the session is currently active.
     *
     * true  → Active session
     * false → Invalidated or disconnected session
     */
    bool active;

public:

    /**
     * @brief Constructs a Session instance.
     *
     * Initializes a new session with the specified session
     * identifier and associated node identifier.
     *
     * @param sid Unique session identifier.
     * @param nid Identifier of the associated node.
     */
    Session(const std::string& sid, const std::string& nid);

    /**
     * @brief Retrieves the node identifier associated with this session.
     *
     * @return The node ID bound to this session.
     */
    std::string getNodeId() const;

    /**
     * @brief Checks whether the session is currently active.
     *
     * @return true if the session is active; otherwise false.
     */
    bool isActive() const;

    /**
     * @brief Invalidates the session.
     *
     * Marks the session as inactive.
     * Typically invoked when a node disconnects
     * or session termination occurs (FR-08).
     */
    void invalidate();

    /**
     * @brief Restores the session to an active state.
     *
     * Allows recovery of previously invalidated sessions,
     * supporting resilience against transient network failures.
     */
    void restore();
};
