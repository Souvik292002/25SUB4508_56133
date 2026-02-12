#include <Logger.h>
#include <iostream>
#include <fstream>
#include <chrono>
#include <iomanip>
#include <filesystem>

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
    std::cout << "[INFO] " << msg << std::endl;
}

void Logger::warning(const std::string& msg) {
    std::cout << "[WARN] " << msg << std::endl;
}

void Logger::error(const std::string& msg) {
    std::cout << "[ERROR] " << msg << std::endl;
}

/* ============================================================
 *  🔥 Per Node File Logging
 * ============================================================ */
void Logger::logToNode(const std::string& nodeId,
                       const std::string& msg) {

    // Create logs folder if not exists
    fs::create_directories("logs");

    std::string fileName = "logs/" + nodeId + ".log";

    std::ofstream file(fileName, std::ios::app);

    if (file.is_open()) {
        file << "[" << currentTimestamp() << "] "
             << msg << std::endl;
        file.close();
    }
}
