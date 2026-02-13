/**
 * @file NetworkUtil.h
 * @brief Provides utility functions for socket-based packet transmission
 *        within the ECSBF framework.
 *
 * The NetworkUtil class encapsulates low-level networking operations
 * used for sending and receiving structured signal packets between
 * endpoint nodes and the ECSBF Core Engine.
 *
 * Architectural Context:
 * - Supports ECSBF Communication Interfaces (SRS Section 4.4)
 * - Operates over TCP/IP persistent connections
 * - Used by both Engine and Client components
 *
 * This utility abstracts raw socket I/O to promote cleaner
 * separation of networking concerns from business logic.
 *
 * @author Group 04
 * @version 1.0
 */

#ifndef NETWORK_UTIL_H
#define NETWORK_UTIL_H

#pragma once

#include <cstddef>
#include <string>

/**
 * @def ECSBF_BUFFER_SIZE
 * @brief Defines the maximum buffer size used for network I/O operations.
 *
 * This constant specifies the size (in bytes) of the buffer
 * allocated for receiving network packets.
 *
 * Default: 1024 bytes
 */
#define ECSBF_BUFFER_SIZE 1024

/**
 * @class NetworkUtil
 * @brief Utility class for TCP packet transmission and reception.
 *
 * Provides static helper methods to:
 * - Send structured data packets over a socket
 * - Receive data packets from a socket
 *
 * This class does not maintain internal state and operates
 * purely as a networking abstraction layer.
 */
class NetworkUtil {
public:

    /**
     * @brief Sends a data packet through the specified socket.
     *
     * This method transmits the provided string data over
     * an active TCP connection.
     *
     * @param sock Active socket descriptor.
     * @param data Serialized data to transmit.
     */
    static void sendPacket(int sock, const std::string& data);

    /**
     * @brief Receives a data packet from the specified socket.
     *
     * Reads incoming data from the socket using the defined
     * buffer size and returns the received payload as a string.
     *
     * @param sock Active socket descriptor.
     * @return Received data payload.
     */
    static std::string receivePacket(int sock);
};

#endif
