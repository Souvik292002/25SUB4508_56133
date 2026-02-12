#include "NodeIdentity.h"

NodeIdentity::NodeIdentity(const std::string& id,
                           const std::string& pass)
    : nodeId(id), password(pass) {}


std::string NodeIdentity::getNodeId() const {
    return nodeId;
}

std::string NodeIdentity::getPassword() const {
    return password;
}
