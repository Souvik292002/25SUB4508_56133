#include "IdentityRegistry.h"

void IdentityRegistry::registerNode(const NodeIdentity& node) {
    nodeDB[node.getNodeId()] = node;
}

bool IdentityRegistry::authenticate(
    const std::string& nodeId,
    const std::string& password
) {
    auto it = nodeDB.find(nodeId);
    if (it == nodeDB.end()) return false;
    return it->second.getPassword() == password;
}
