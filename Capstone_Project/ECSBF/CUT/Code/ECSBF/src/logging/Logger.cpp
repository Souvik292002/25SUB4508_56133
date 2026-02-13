/**
 * @file Logger.cpp
 * @brief Implements the centralized logging subsystem for ECSBF.
 *
 * This file provides the runtime implementation of the Logger class,
 * which delivers:
 * - Multi-level logging (FATAL, INFO, WARNING, DEBUG)
 * - Thread-safe write operations
 * - Automatic log rotation based on file size
 * - Timestamped structured log entries
 *
 * Architectural Alignment:
 * - Supports ECSBF_FR_12 (Diagnostic Logging and Observability)
 * - Ensures safe concurrent logging across multi-threaded Engine
 * - Provides structured operational traceability
 */

#include "Logger.h"
#include <chrono>
#include <iomanip>
#include <sstream>
#include <filesystem>

namespace fs = std::filesystem;


/**
 * ============================================================
 *  Constructor
 * ============================================================
 *
 * Initializes the Logger singleton instance.
 * - Sets default log level to INFO
 * - Ensures log directory exists
 */
Logger::Logger() : currentLevel(INFO) {
    fs::create_directories("logs");
}


/**
 * ============================================================
 *  Destructor
 * ============================================================
 *
 * Ensures all open file streams are properly closed
 * during application shutdown.
 */
Logger::~Logger() {
    for (auto& pair : logFiles) {
        if (pair.second.is_open())
            pair.second.close();
    }
}


/**
 * ============================================================
 *  Singleton Accessor
 * ============================================================
 *
 * Returns the single Logger instance.
 * Ensures centralized logging across the entire ECSBF system.
 */
Logger& Logger::getInstance() {
    static Logger instance;
    return instance;
}


/**
 * ============================================================
 *  Set Log Level
 * ============================================================
 *
 * Configures the minimum severity level required
 * for log messages to be written.
 */
void Logger::setLogLevel(LogLevel level) {
    currentLevel = level;
}


/**
 * ============================================================
 *  Timestamp Generator
 * ============================================================
 *
 * Generates a formatted timestamp string in:
 * YYYY-MM-DD HH:MM:SS format
 *
 * Used to prefix every log entry.
 */
std::string Logger::getCurrentTimestamp() {
    auto now = std::chrono::system_clock::now();
    auto time = std::chrono::system_clock::to_time_t(now);

    std::ostringstream oss;
    oss << std::put_time(std::localtime(&time),
                         "%Y-%m-%d %H:%M:%S");
    return oss.str();
}


/**
 * ============================================================
 *  Log Level Conversion
 * ============================================================
 *
 * Converts LogLevel enum values into
 * human-readable string representations.
 */
std::string Logger::levelToString(LogLevel level) {
    switch (level) {
        case FATAL:   return "FATAL";
        case INFO:    return "INFO";
        case WARNING: return "WARNING";
        case DEBUG:   return "DEBUG";
        default:      return "UNKNOWN";
    }
}


/**
 * ============================================================
 *  Log Rotation Handler
 * ============================================================
 *
 * Checks the current file size and rotates the log file
 * if it exceeds the configured maximum size.
 *
 * Rotation Strategy:
 * - Close current file
 * - Rename existing file to .1 backup
 * - Reopen fresh log file
 */
void Logger::rotateIfNeeded(const std::string& fileName) {

    std::string fullPath = "logs/" + fileName;

    if (!fs::exists(fullPath)) return;

    auto size = fs::file_size(fullPath);

    if (size >= maxFileSize) {

        logFiles[fileName].close();

        std::string backup = fullPath + ".1";

        if (fs::exists(backup))
            fs::remove(backup);

        fs::rename(fullPath, backup);

        logFiles[fileName].open(fullPath, std::ios::app);
    }
}


/**
 * ============================================================
 *  Main Logging Function
 * ============================================================
 *
 * Writes a formatted log entry to the specified file.
 *
 * Behavior:
 * - Filters based on configured log level
 * - Ensures thread-safe file access
 * - Opens file lazily if not already open
 * - Performs rotation check before writing
 * - Writes timestamped, severity-tagged message
 */
void Logger::log(const std::string& fileName,
                 LogLevel level,
                 const std::string& message) {

    /* Severity filtering */
    if (level > currentLevel) return;

    /* Thread-safe write protection */
    std::lock_guard<std::mutex> lock(logMutex);

    std::string fullPath = "logs/" + fileName;

    /*
     * Open file if not already opened.
     * Lazy initialization avoids unnecessary file handles.
     */
    if (logFiles.find(fileName) == logFiles.end()) {
        logFiles[fileName].open(fullPath, std::ios::app);
    }

    /* Ensure log rotation policy compliance */
    rotateIfNeeded(fileName);

    /*
     * Structured log format:
     * [Timestamp] [LEVEL] Message
     */
    logFiles[fileName]
        << "[" << getCurrentTimestamp() << "] ["
        << levelToString(level) << "] "
        << message << std::endl;
}
