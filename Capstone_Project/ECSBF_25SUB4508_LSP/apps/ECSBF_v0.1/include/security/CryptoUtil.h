#pragma once
#include <string>

class CryptoUtil {
public:
    static std::string encrypt(const std::string& data);
    static std::string decrypt(const std::string& data);
};
