#ifndef NETWORK_UTIL_H
#define NETWORK_UTIL_H

#include <string>

class NetworkUtil {
public:
    static void sendPacket(int sock, const std::string& data);
    static std::string receivePacket(int sock);
};

#endif
