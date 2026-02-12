#ifndef NODE_IDENTITY_H
#define NODE_IDENTITY_H

#include <string>

class NodeIdentity {
private:
    std::string nodeId;
    std::string password;

public:
    NodeIdentity() = default;
    NodeIdentity(const std::string& id, const std::string& pass);

    std::string getNodeId() const;
    std::string getPassword() const;
};

#endif
