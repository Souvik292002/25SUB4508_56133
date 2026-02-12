#include <NetworkUtil.h>
#include <unistd.h>
#include <sys/socket.h>

/*
 * ============================================================
 *  Module: ECSBF Network Utilities
 *  File  : NetworkUtil.cpp
 * ------------------------------------------------------------
 *  Description:
 *  Provides concrete implementations for low-level socket
 *  send and receive operations used throughout the Enterprise
 *  Concurrent Signal Broadcast Framework (ECSBF).
 *
 *  This module abstracts raw socket I/O to ensure consistent
 *  data transmission semantics across Core Engine and client
 *  components.
 *
 *  The implementation is intentionally minimal to keep
 *  transport concerns isolated from higher-level logic such
 *  as authentication, session management, and broadcasting.
 * ============================================================
 */


/*
 * ============================================================
 *  Send Packet
 * ============================================================
 *  Transmits a serialized data payload over an established
 *  socket connection.
 *
 *  Parameters:
 *   - sock : Valid, connected socket descriptor
 *   - data : Serialized message payload to transmit
 *
 *  Behavior:
 *   - Performs a best-effort send operation
 *   - Assumes the socket is in a valid connected state
 *
 *  Note:
 *   - Error handling and retry policies are intentionally
 *     delegated to the calling context to preserve flexibility
 *     and simplicity at the utility level.
 * ============================================================
 */
void NetworkUtil::sendPacket(int sock, const std::string& data) {
    send(sock, data.c_str(), data.size(), 0);
}


/*
 * ============================================================
 *  Receive Packet
 * ============================================================
 *  Receives an inbound data payload from an established
 *  socket connection.
 *
 *  Parameters:
 *   - sock : Valid, connected socket descriptor
 *
 *  Returns:
 *   - String containing the received data payload
 *
 *  Behavior:
 *   - Blocks until data is received or the connection is closed
 *   - Reads up to a fixed buffer size
 *
 *  Note:
 *   - An empty return value typically indicates a closed
 *     connection or remote shutdown
 *   - Message framing and higher-level protocol handling are
 *     intentionally managed outside this utility
 * ============================================================
 */
std::string NetworkUtil::receivePacket(int sock) {
    char buffer[ECSBF_BUFFER_SIZE] = {0};
    recv(sock, buffer, sizeof(buffer), 0);
    return std::string(buffer);
}
