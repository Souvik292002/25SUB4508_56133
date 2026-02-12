#include "Client.h"

/*
 * ============================================================
 *  ECSBF Client Entry Point
 * ============================================================
 *  Description:
 *  This file defines the entry point for the ECSBF Client
 *  application.
 *
 *  The client acts as an endpoint node within the Enterprise
 *  Concurrent Signal Broadcast Framework (ECSBF), responsible
 *  for:
 *   - Establishing a connection to the ECSBF Core Engine
 *   - Participating in authentication and session workflows
 *   - Sending and receiving real-time broadcast messages
 *
 *  The main function is intentionally minimal and delegates
 *  all operational responsibilities to the Client class.
 * ============================================================
 */

int main() {
    /*
     * --------------------------------------------------------
     *  Client Initialization
     * --------------------------------------------------------
     *  Creates a client instance configured to connect to the
     *  ECSBF Core Engine running on the local host.
     *
     *  Parameters:
     *   - IP Address : 127.0.0.1 (loopback)
     *   - Port       : 4096
     * --------------------------------------------------------
     */
    Client client("127.0.0.1", 4096);

    /*
     * --------------------------------------------------------
     *  Start Client Lifecycle
     * --------------------------------------------------------
     *  Initiates connection, authentication, and interactive
     *  communication with the ECSBF Core Engine.
     * --------------------------------------------------------
     */
    client.connectToEngine();

    /*
     * --------------------------------------------------------
     *  Normal Program Termination
     * --------------------------------------------------------
     */
    return 0;
}
