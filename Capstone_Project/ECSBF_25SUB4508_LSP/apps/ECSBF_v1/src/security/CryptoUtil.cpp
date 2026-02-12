#include <CryptoUtil.h>
#include <random>

std::string CryptoUtils::generateKey() {

    const std::string chars =
        "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "0123456789";

    std::string key;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, chars.size() - 1);

    for (int i = 0; i < 16; ++i)
        key += chars[dist(gen)];

    return key;
}

std::string CryptoUtils::encrypt(const std::string& data,
                                 const std::string& key) {

    std::string result = data;

    for (size_t i = 0; i < data.size(); ++i)
        result[i] = data[i] ^ key[i % key.size()];

    return result;
}

std::string CryptoUtils::decrypt(const std::string& data,
                                 const std::string& key) {

    return encrypt(data, key);  // XOR symmetric
}
