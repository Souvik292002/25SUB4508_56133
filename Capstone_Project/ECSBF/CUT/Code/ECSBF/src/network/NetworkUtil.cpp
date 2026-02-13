/**
 * @file NetworkUtil.cpp
 * @brief Implements low-level TCP communication utilities for ECSBF.
 *
 * This file provides the implementation of the NetworkUtil class,
 * which abstracts raw socket operations for:
 * - Sending structured signal packets
 * - Receiving incoming packets
 *
 * Architectural Context:
 * - Supports ECSBF Communication Interfaces (SRS Section 4.4)
 * - Operates over persistent TCP/IP connections
 * - Used by both Client and Core Engine modules
 *
 * Design Intent:
 * This utility layer isolates networking concerns from
 * business logic, promoting cleaner modular architecture.
 */

#include <NetworkUtil.h>
#include <unistd.h>
#include <sys/socket.h>

/**
 * ============================================================
 *  Send Packet
 * ============================================================
 *
 * Transmits the provided data buffer through the specified
 * socket descriptor.
 *
 * Parameters:
 * - sock : Active TCP socket descriptor
 * - data : Serialized payload to transmit
 *
 * Note:
 * This function assumes that the socket is already connected
 * and valid. Error handling is expected to be managed by
 * higher-level components.
 */
void NetworkUtil::sendPacket(int sock, const std::string& data) {
    send(sock, data.c_str(), data.size(), 0);
}


/**
 * ============================================================
 *  Receive Packet
 * ============================================================
 *
 * Receives data from the specified socket into a fixed-size buffer.
 *
 * Behavior:
 * - Reads up to ECSBF_BUFFER_SIZE - 1 bytes
 * - Ensures null-terminated string safety
 * - Returns empty string if connection closed or error occurs
 *
 * Return Value:
 * - Non-empty string → Valid received payload
 * - Empty string     → Disconnection or receive failure
 */
std::string NetworkUtil::receivePacket(int sock) {

    char buffer[ECSBF_BUFFER_SIZE] = {0};

    ssize_t bytesReceived =
        recv(sock, buffer, sizeof(buffer) - 1, 0);

    /*
     * If zero or negative bytes are received:
     * - Zero indicates remote disconnection
     * - Negative indicates socket error
     */
    if (bytesReceived <= 0) {
        return "";
    }

    /* Ensure explicit null-termination for safety */
    buffer[bytesReceived] = '\0';

    return std::string(buffer);
}
