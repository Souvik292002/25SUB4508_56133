#include <Logger.h>
#include <iostream>

/*
 * ============================================================
 *  Module: ECSBF Diagnostics & Telemetry
 *  File  : Logger.cpp
 * ------------------------------------------------------------
 *  Description:
 *  Provides the concrete implementation of the Logger utility
 *  used throughout the Enterprise Concurrent Signal Broadcast
 *  Framework (ECSBF).
 *
 *  This implementation emits log messages to standard output
 *  with severity-level prefixes.
 *
 *  The Logger serves as a centralized observability mechanism,
 *  enabling visibility into system behavior, lifecycle events,
 *  and error conditions during execution.
 *
 *  Note:
 *  This implementation is intentionally minimal and can be
 *  extended or redirected to file-based logging, syslog, or
 *  external monitoring systems without modifying caller code.
 * ============================================================
 */


/*
 * ============================================================
 *  Informational Log
 * ============================================================
 *  Emits non-critical informational messages describing normal
 *  system operation.
 *
 *  Typical Usage:
 *   - Startup and shutdown notifications
 *   - Connection establishment and teardown
 *   - High-level state transitions
 * ============================================================
 */
void Logger::info(const std::string& msg) {
    std::cout << "[INFO] " << msg << std::endl;
}


/*
 * ============================================================
 *  Warning Log
 * ============================================================
 *  Emits warnings for abnormal but recoverable conditions.
 *
 *  Typical Usage:
 *   - Authentication retries
 *   - Partial failures
 *   - Degraded or unexpected states
 * ============================================================
 */
void Logger::warning(const std::string& msg) {
    std::cout << "[WARN] " << msg << std::endl;
}


/*
 * ============================================================
 *  Error Log
 * ============================================================
 *  Emits error messages indicating critical or unrecoverable
 *  failures requiring attention.
 *
 *  Typical Usage:
 *   - Security violations
 *   - Fatal network errors
 *   - System-level failures
 * ============================================================
 */
void Logger::error(const std::string& msg) {
    std::cout << "[ERROR] " << msg << std::endl;
}
