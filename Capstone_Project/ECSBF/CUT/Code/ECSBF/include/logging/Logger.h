/**
 * @file Logger.h
 * @brief Defines the centralized logging system for ECSBF.
 *
 * The Logger class provides a thread-safe, multi-level logging
 * mechanism aligned with ECSBF_FR_12 (Diagnostic Logging and Observability).
 *
 * Key Features:
 * - Supports multiple log levels (FATAL, INFO, WARNING, DEBUG)
 * - Thread-safe logging using mutex synchronization
 * - Log file rotation based on maximum file size
 * - Singleton design pattern to ensure a single global logger instance
 *
 * Architectural Context:
 * The Logger supports observability, debugging, auditing,
 * and operational monitoring across the ECSBF framework.
 *
 * This component ensures that logging operations do not introduce
 * race conditions in a concurrent multi-threaded environment.
 *
 * @author Group 04
 * @version 1.0
 */

#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>
#include <mutex>
#include <unordered_map>

/**
 * @enum LogLevel
 * @brief Defines severity levels for logging.
 *
 * These levels correspond to ECSBF diagnostic logging requirements:
 * - FATAL   : Critical system failure conditions
 * - INFO    : Normal operational events
 * - WARNING : Abnormal but non-critical conditions
 * - DEBUG   : Detailed diagnostic information
 */
enum LogLevel {
    FATAL = 0,
    INFO = 1,
    WARNING = 2,
    DEBUG = 3
};

/**
 * @class Logger
 * @brief Thread-safe singleton logging utility for ECSBF.
 *
 * The Logger class:
 * - Maintains separate log files identified by file names
 * - Supports runtime log level filtering
 * - Performs automatic file rotation when size threshold is exceeded
 * - Ensures synchronized write operations across threads
 *
 * Design Pattern:
 * Implements the Singleton pattern to guarantee a single
 * global logging instance throughout the application lifecycle.
 */
class Logger {
private:

    /**
     * @brief Maximum allowed size per log file (in bytes).
     *
     * When exceeded, log rotation is triggered.
     * Default: 5 MB per file.
     */
    size_t maxFileSize = 5 * 1024 * 1024;

    /**
     * @brief Mapping of file names to output file streams.
     *
     * Key   : Log file name
     * Value : Corresponding output stream
     *
     * Enables dynamic creation and management of multiple log files.
     */
    std::unordered_map<std::string, std::ofstream> logFiles;

    /**
     * @brief Mutex ensuring thread-safe logging operations.
     *
     * Protects file writes and file rotation from race conditions.
     */
    std::mutex logMutex;

    /**
     * @brief Current active log level threshold.
     *
     * Messages below this level will be ignored.
     */
    LogLevel currentLevel;

    /**
     * @brief Private constructor for Singleton pattern.
     *
     * Prevents direct instantiation.
     */
    Logger();

    /**
     * @brief Destructor responsible for cleanup of log resources.
     */
    ~Logger();

    /**
     * @brief Generates the current timestamp string.
     *
     * Used to prefix log entries for traceability.
     *
     * @return Formatted timestamp string.
     */
    std::string getCurrentTimestamp();

    /**
     * @brief Converts a LogLevel enum to its string representation.
     *
     * @param level Log severity level.
     * @return Corresponding string label.
     */
    std::string levelToString(LogLevel level);

    /**
     * @brief Checks file size and rotates log if necessary.
     *
     * Ensures that log files do not exceed the configured
     * maximum size threshold.
     *
     * @param fileName Name of the log file to check.
     */
    void rotateIfNeeded(const std::string& fileName);

public:

    /**
     * @brief Retrieves the singleton Logger instance.
     *
     * @return Reference to the global Logger instance.
     */
    static Logger& getInstance();

    /**
     * @brief Sets the minimum log level threshold.
     *
     * Messages below this level will not be written to logs.
     *
     * @param level Desired log level.
     */
    void setLogLevel(LogLevel level);

    /**
     * @brief Writes a log entry to the specified file.
     *
     * This is the primary logging interface used across the ECSBF system.
     * It records timestamped, level-tagged messages in a thread-safe manner.
     *
     * @param fileName Target log file name.
     * @param level Severity level of the message.
     * @param message Log message content.
     */
    void log(const std::string& fileName,
             LogLevel level,
             const std::string& message);

    /**
     * @brief Deleted copy constructor to enforce Singleton pattern.
     */
    Logger(const Logger&) = delete;

    /**
     * @brief Deleted copy assignment operator to enforce Singleton pattern.
     */
    Logger& operator=(const Logger&) = delete;
};

#endif
