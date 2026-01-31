#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <mutex>

class Logger {
private:
    std::mutex logMutex;
    std::string logFile;

public:
    explicit Logger(const std::string& filePath);
    void log(const std::string& message);
};

#endif
