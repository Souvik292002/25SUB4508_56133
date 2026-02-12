#pragma once
#include <string>

class Session {
private:
    std::string sessionId;
    std::string nodeId;
    bool active;

public:
    Session(const std::string& sid, const std::string& nid);

    std::string getNodeId() const;
    bool isActive() const;
    void invalidate();
    void restore();
};
