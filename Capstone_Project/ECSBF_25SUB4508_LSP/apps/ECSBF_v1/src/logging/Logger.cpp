#include <Logger.h>

#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <filesystem>
#include <mutex>

/*
 *  Thread-safe file logging mutex
 */
static std::mutex logMutex;

/*
 *  Generate formatted timestamp
 */
static std::string getTimestamp()
{
    auto now = std::chrono::system_clock::now();
    std::time_t nowTime =
        std::chrono::system_clock::to_time_t(now);

    std::tm* tmPtr = std::localtime(&nowTime);

    std::ostringstream oss;
    oss << std::put_time(tmPtr, "%Y-%m-%d %H:%M:%S");

    return oss.str();
}

/*
 * Console Logs
 */
void Logger::info(const std::string& msg)
{
    std::cout << "[INFO] " << msg << std::endl;
}

void Logger::warning(const std::string& msg)
{
    std::cout << "[WARN] " << msg << std::endl;
}

void Logger::error(const std::string& msg)
{
    std::cout << "[ERROR] " << msg << std::endl;
}

/*
 * ============================================================
 *  Per-Node Log File Writer
 * ============================================================
 *  - Auto creates logs directory
 *  - Creates file per node
 *  - Appends logs
 *  - Adds timestamp
 *  - Thread safe
 * ============================================================
 */
void Logger::logToNode(const std::string& nodeId,
                       const std::string& message)
{
    std::lock_guard<std::mutex> lock(logMutex);

    // Create logs folder if not exists
    std::filesystem::create_directory("logs");

    std::string filename = "logs/" + nodeId + ".log";

    std::ofstream file(filename, std::ios::app);

    if (file.is_open())
    {
        file << "[" << getTimestamp() << "] "
             << message << std::endl;
    }
}
