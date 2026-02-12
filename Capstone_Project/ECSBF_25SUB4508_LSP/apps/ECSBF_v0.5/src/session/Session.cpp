#include <Session.h>

Session::Session(const std::string& sid,
                 const std::string& nid,
                 const std::string& key)
    : sessionId(sid),
      nodeId(nid),
      encryptionKey(key),
      active(true) {}

std::string Session::getNodeId() const {
    return nodeId;
}

std::string Session::getKey() const {
    return encryptionKey;
}

bool Session::isActive() const {
    return active;
}

void Session::invalidate() {
    active = false;
}

void Session::restore() {
    active = true;
}
