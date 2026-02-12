#ifndef LOGGER_H
#define LOGGER_H

#include <string>

class Logger {
public:
    static void info(const std::string& msg);
    static void warning(const std::string& msg);
    static void error(const std::string& msg);

    // 🔥 NEW
    static void logToNode(const std::string& nodeId,
                          const std::string& msg);
};

#endif
