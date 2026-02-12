#ifndef NETWORK_UTIL_H
#define NETWORK_UTIL_H

#pragma once
#include <cstddef>
#include <string>
#define ECSBF_BUFFER_SIZE 1024
/*
 * ============================================================
 *  File: NetworkUtil.h
 *  Module: ECSBF Network Utilities
 * ------------------------------------------------------------
 *  Description:
 *  This header defines the NetworkUtil utility class, which
 *  provides low-level, reusable networking helpers for data
 *  transmission within the Enterprise Concurrent Signal
 *  Broadcast Framework (ECSBF).
 *
 *  The utilities abstract common socket send/receive patterns
 *  to ensure consistency, reliability, and maintainability
 *  across both Core Engine and endpoint node implementations.
 *
 *  This module supports secure and efficient signal delivery
 *  across the distributed ECSBF communication backbone.
 * ============================================================
 */



/*
 * ------------------------------------------------------------
 *  Class: NetworkUtil
 * ------------------------------------------------------------
 *  Responsibility:
 *  Provides stateless helper functions for transmitting and
 *  receiving data packets over established socket connections.
 *
 *  Design Characteristics:
 *   - Static utility methods
 *   - No internal state or resource ownership
 *   - Reusable across multiple ECSBF components
 *
 *  This abstraction ensures that transport-level concerns
 *  remain isolated from business and session logic.
 * ------------------------------------------------------------
 */
class NetworkUtil {
public:
    /*
     * Sends a data packet over an established socket connection.
     *
     * Parameters:
     *  - sock : Valid socket descriptor
     *  - data : Serialized payload to be transmitted
     *
     * Intended Use:
     *  - Signal broadcasts from the Core Engine
     *  - Control or data messages from endpoint nodes
     *
     * Note:
     *  Error handling and retry strategies are expected to be
     *  implemented by the calling context where required.
     */
    static void sendPacket(int sock, const std::string& data);

    /*
     * Receives a data packet from an established socket
     * connection.
     *
     * Parameters:
     *  - sock : Valid socket descriptor
     *
     * Returns:
     *  - Serialized payload received from the remote endpoint
     *
     * Intended Use:
     *  - Receiving broadcasted signals
     *  - Handling inbound control messages
     *
     * Note:
     *  This method assumes a valid, open socket and does not
     *  perform connection establishment or teardown.
     */
    static std::string receivePacket(int sock);
};

#endif
