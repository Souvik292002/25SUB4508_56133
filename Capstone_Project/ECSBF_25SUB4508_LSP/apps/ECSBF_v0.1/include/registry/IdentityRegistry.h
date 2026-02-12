#pragma once
#include <unordered_map>
#include <string>
#include "NodeIdentity.h"

class IdentityRegistry {
    std::unordered_map<std::string, NodeIdentity> nodeDB;

public:
    void registerNode(const NodeIdentity& node);
    bool authenticate(const std::string& nodeId, const std::string& password);
};
