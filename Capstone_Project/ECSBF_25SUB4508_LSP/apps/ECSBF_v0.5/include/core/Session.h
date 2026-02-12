#pragma once
#include <string>

class Session {
private:
    std::string sessionId;
    std::string nodeId;
    std::string encryptionKey;
    bool active;

public:
    Session(const std::string& sid,
            const std::string& nid,
            const std::string& key);

    std::string getNodeId() const;
    std::string getKey() const;

    bool isActive() const;
    void invalidate();
    void restore();
};
