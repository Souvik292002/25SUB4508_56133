#include <ECSBF_CoreEngine.h>

/*
 * ============================================================
 *  ECSBF Core Engine Entry Point
 * ============================================================
 *  Description:
 *  This file defines the entry point for the ECSBF Core Engine
 *  application.
 *
 *  The Core Engine acts as the centralized coordination and
 *  signal-distribution backbone of the Enterprise Concurrent
 *  Signal Broadcast Framework (ECSBF).
 *
 *  Responsibilities initiated from this entry point include:
 *   - Starting the server-side networking layer
 *   - Accepting concurrent endpoint node connections
 *   - Managing authentication, sessions, and broadcasting
 *
 *  The main function intentionally delegates all operational
 *  responsibilities to the ECSBF_CoreEngine class to preserve
 *  clean separation of concerns.
 * ============================================================
 */

int main() {
    /*
     * --------------------------------------------------------
     *  Core Engine Initialization
     * --------------------------------------------------------
     *  Creates an ECSBF Core Engine instance configured to
     *  listen for incoming node connections on the specified
     *  port.
     *
     *  Port:
     *   - 4096 : Default ECSBF engine listening port
     * --------------------------------------------------------
     */
    ECSBF_CoreEngine engine(4096);

    /*
     * --------------------------------------------------------
     *  Start Engine Lifecycle
     * --------------------------------------------------------
     *  Enters the Core Engine execution loop, initializing
     *  networking infrastructure and handling node traffic.
     *
     *  This call blocks for the lifetime of the engine.
     * --------------------------------------------------------
     */
    engine.startEngine();

    /*
     * --------------------------------------------------------
     *  Normal Program Termination
     * --------------------------------------------------------
     *  This point is reached only if the engine shuts down
     *  gracefully.
     * --------------------------------------------------------
     */
    return 0;
}
