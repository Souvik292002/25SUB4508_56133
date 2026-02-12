#include <CryptoUtil.h>
#include <sstream>
#include <iomanip>

/* ============================================================
 *  Simple XOR Encryption
 * ============================================================ */

std::string CryptoUtil::encrypt(const std::string& data,
                                 const std::string& key) {

    std::string result;

    for (size_t i = 0; i < data.size(); i++) {
        char encryptedChar = data[i] ^ key[i % key.size()];
        result += encryptedChar;
    }

    return result;
}

std::string CryptoUtil::decrypt(const std::string& data,
                                 const std::string& key) {

    std::string result;

    for (size_t i = 0; i < data.size(); i++) {
        char decryptedChar = data[i] ^ key[i % key.size()];
        result += decryptedChar;
    }

    return result;
}

std::string CryptoUtil::generateKey() {
    return "ECSBF_SECRET_KEY";  // fixed demo key
}
