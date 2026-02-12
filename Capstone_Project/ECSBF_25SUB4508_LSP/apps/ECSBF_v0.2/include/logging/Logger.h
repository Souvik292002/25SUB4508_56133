#ifndef LOGGER_H
#define LOGGER_H

/*
 * ============================================================
 *  File: Logger.h
 *  Module: ECSBF Diagnostics & Telemetry
 * ------------------------------------------------------------
 *  Description:
 *  This header defines the Logger utility class used throughout
 *  the Enterprise Concurrent Signal Broadcast Framework (ECSBF)
 *  for emitting structured diagnostic and operational logs.
 *
 *  The Logger provides a centralized, static interface for
 *  recording system events at multiple severity levels,
 *  enabling observability, debugging, and operational auditing.
 *
 *  Logging is intentionally abstracted to allow future
 *  redirection to files, remote log collectors, or monitoring
 *  pipelines without impacting calling code.
 * ============================================================
 */

#include <string>

/*
 * ------------------------------------------------------------
 *  Class: Logger
 * ------------------------------------------------------------
 *  Responsibility:
 *  Provides a lightweight, stateless logging interface for
 *  emitting diagnostic messages across the ECSBF system.
 *
 *  Design Characteristics:
 *   - Static methods for ease of access
 *   - No instance lifecycle management
 *   - Severity-based log categorization
 *
 *  This class is intended to be used by both Core Engine and
 *  endpoint components to ensure consistent telemetry output.
 * ------------------------------------------------------------
 */
class Logger {
public:
    /*
     * Emits an informational log message.
     *
     * Intended Use:
     *  - Normal system operations
     *  - Lifecycle events (startup, shutdown, connections)
     *  - High-level state transitions
     */
    static void info(const std::string& msg);

    /*
     * Emits a warning log message.
     *
     * Intended Use:
     *  - Recoverable errors
     *  - Degraded system states
     *  - Unexpected but non-fatal conditions
     */
    static void warning(const std::string& msg);

    /*
     * Emits an error log message.
     *
     * Intended Use:
     *  - Critical failures
     *  - Security violations
     *  - Irrecoverable system errors
     *
     * Error logs typically require immediate attention and
     * may trigger alerts in production environments.
     */
    static void error(const std::string& msg);
};

#endif
