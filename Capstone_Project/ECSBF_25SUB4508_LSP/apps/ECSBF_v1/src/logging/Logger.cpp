#include <Logger.h>
#include <fstream>
#include <chrono>
#include <iomanip>
#include <filesystem>
#include <mutex>
#include <sstream>

std::mutex logMutex;

namespace fs = std::filesystem;

/* ============================================================
 *  Helper: Get Current Timestamp
 * ============================================================ */
std::string currentTimestamp() {

    auto now = std::chrono::system_clock::now();
    auto time = std::chrono::system_clock::to_time_t(now);

    std::tm* tmPtr = std::localtime(&time);

    std::ostringstream oss;
    oss << std::put_time(tmPtr, "%Y-%m-%d %H:%M:%S");

    return oss.str();
}

/* ============================================================
 *  Console Logs
 * ============================================================ */
void Logger::info(const std::string& msg) {
    std::lock_guard<std::mutex> lock(logMutex);

    fs::create_directories("logs");

    std::ofstream file("logs/engine.log", std::ios::app);

    if (file.is_open()) {
        file << "[" << currentTimestamp() << "] "
             << "[INFO] " << msg << std::endl;
    }
}

void Logger::warning(const std::string& msg) {
    std::lock_guard<std::mutex> lock(logMutex);

    fs::create_directories("logs");

    std::ofstream file("logs/engine.log", std::ios::app);

    if (file.is_open()) {
        file << "[" << currentTimestamp() << "] "
             << "[WARN] " << msg << std::endl;
    }
}

void Logger::error(const std::string& msg) {
    std::lock_guard<std::mutex> lock(logMutex);

    fs::create_directories("logs");

    std::ofstream file("logs/engine.log", std::ios::app);

    if (file.is_open()) {
        file << "[" << currentTimestamp() << "] "
             << "[ERROR] " << msg << std::endl;
    }
}


/* ============================================================
 *  🔥 Per Node File Logging
 * ============================================================ */
void Logger::logToNode(const std::string& nodeId,
                       const std::string& msg) {

    std::lock_guard<std::mutex> lock(logMutex);

    fs::create_directories("logs");

    std::string fileName = "logs/" + nodeId + ".log";

    std::ofstream file(fileName, std::ios::app);

    if (file.is_open()) {
        file << "[" << currentTimestamp() << "] "
             << msg << std::endl;
    }
}






































