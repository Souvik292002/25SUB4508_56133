#pragma once
#include <string>

class CryptoUtils {
public:
    static std::string generateKey();
    static std::string encrypt(const std::string& data,
                               const std::string& key);
    static std::string decrypt(const std::string& data,
                               const std::string& key);
};
