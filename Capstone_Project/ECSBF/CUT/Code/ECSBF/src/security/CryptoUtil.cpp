/**
 * @file CryptoUtil.cpp
 * @brief Implements cryptographic utilities for secure communication
 *        within the ECSBF framework.
 *
 * This module provides:
 * - Symmetric encryption using XOR-based transformation
 * - Symmetric decryption (same XOR operation)
 * - Session key generation utility
 *
 * Architectural Alignment:
 * - Supports ECSBF_FR_10 (Encryption of sensitive data)
 * - Supports ECSBF_FR_11 (Secure payload decryption at endpoints)
 *
 * Security Note:
 * The current implementation uses a simple XOR-based algorithm
 * for demonstration and educational purposes. In a production
 * environment, a standardized cryptographic library (e.g., AES)
 * should be used for stronger security guarantees.
 */

#include <CryptoUtil.h>
#include <sstream>
#include <iomanip>

/**
 * ============================================================
 *  Encrypt
 * ============================================================
 *
 * Applies symmetric XOR encryption to the input data
 * using the provided session key.
 *
 * Behavior:
 * - Each character of the data is XORed with a corresponding
 *   character from the key (cyclically applied).
 * - Produces encrypted binary-safe string output.
 *
 * Parameters:
 * - data : Plaintext input string
 * - key  : Session encryption key
 *
 * Returns:
 * - Encrypted string
 */
std::string CryptoUtil::encrypt(const std::string& data,
                                 const std::string& key) {

    std::string result;

    for (size_t i = 0; i < data.size(); i++) {

        /*
         * XOR operation with cyclic key indexing.
         * Ensures reversible symmetric encryption.
         */
        char encryptedChar =
            data[i] ^ key[i % key.size()];

        result += encryptedChar;
    }

    return result;
}


/**
 * ============================================================
 *  Decrypt
 * ============================================================
 *
 * Applies symmetric XOR decryption to the encrypted data.
 *
 * Since XOR is a reversible operation:
 *   plaintext = encrypted XOR key
 *
 * This implementation mirrors the encrypt() logic.
 *
 * Parameters:
 * - data : Encrypted input string
 * - key  : Session encryption key
 *
 * Returns:
 * - Decrypted plaintext string
 */
std::string CryptoUtil::decrypt(const std::string& data,
                                 const std::string& key) {

    std::string result;

    for (size_t i = 0; i < data.size(); i++) {

        /*
         * Same XOR operation restores original plaintext.
         */
        char decryptedChar =
            data[i] ^ key[i % key.size()];

        result += decryptedChar;
    }

    return result;
}


/**
 * ============================================================
 *  Generate Key
 * ============================================================
 *
 * Generates a session-level encryption key.
 *
 * Current Implementation:
 * - Returns a fixed demonstration key
 *
 * Note:
 * In a production-ready system, this method should:
 * - Generate cryptographically secure random keys
 * - Ensure sufficient entropy
 * - Avoid hardcoded values
 *
 * Returns:
 * - Session encryption key string
 */
std::string CryptoUtil::generateKey() {
    return "ECSBF_SECRET_KEY";  // Fixed demonstration key
}
