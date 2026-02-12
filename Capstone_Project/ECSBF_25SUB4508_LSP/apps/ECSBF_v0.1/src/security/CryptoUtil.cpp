#include "CryptoUtil.h"

std::string CryptoUtil::encrypt(const std::string& data) {
    return "ENC{" + data + "}";
}

std::string CryptoUtil::decrypt(const std::string& data) {
    return data.substr(4, data.size() - 5);
}
