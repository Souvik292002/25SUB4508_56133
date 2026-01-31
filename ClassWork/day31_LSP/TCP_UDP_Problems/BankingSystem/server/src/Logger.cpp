#include "../include/Logger.h"
#include <fstream>
#include <ctime>

Logger::Logger(const std::string& filePath)
    : logFile(filePath) {}

void Logger::log(const std::string& message) {
    std::lock_guard<std::mutex> lock(logMutex);

    std::ofstream file(logFile, std::ios::app);
    time_t now = time(nullptr);

    file << "[" << ctime(&now) << "] "
         << message << "\n";
}
