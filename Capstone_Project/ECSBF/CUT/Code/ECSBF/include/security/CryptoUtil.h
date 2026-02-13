/**
 * @file CryptoUtil.h
 * @brief Provides cryptographic utility functions for secure data handling
 *        within the ECSBF framework.
 *
 * The CryptoUtil class encapsulates encryption and decryption
 * operations used to protect sensitive data such as:
 * - Session identifiers
 * - Credentials
 * - Signal payloads
 *
 * Architectural Context:
 * - Supports Cryptographic Protection (ECSBF_FR_10)
 * - Supports Secure Payload Decryption (ECSBF_FR_11)
 *
 * This class is designed as a stateless utility component,
 * providing static methods for encryption, decryption,
 * and secure key generation.
 *
 * @author Group 04
 * @version 1.0
 */

#pragma once

#include <string>

/**
 * @class CryptoUtil
 * @brief Stateless utility class for encryption and decryption.
 *
 * The CryptoUtil class provides:
 * - Symmetric encryption of data using a session key
 * - Secure decryption of encrypted payloads
 * - Generation of session-level encryption keys
 *
 * All methods are static, reflecting its role as a pure
 * cryptographic helper module without internal state.
 */
class CryptoUtil {
public:

    /**
     * @brief Encrypts the provided data using the specified key.
     *
     * This method applies encryption to sensitive identifiers
     * or signal payloads before transmission over the network.
     *
     * @param data Plaintext data to encrypt.
     * @param key Encryption key used for securing the data.
     * @return Encrypted data as a string.
     */
    static std::string encrypt(const std::string& data,
                               const std::string& key);

    /**
     * @brief Generates a new cryptographic session key.
     *
     * This key may be used for secure communication
     * between a node and the ECSBF Core Engine.
     *
     * @return Newly generated encryption key.
     */
    static std::string generateKey();

    /**
     * @brief Decrypts encrypted data using the specified key.
     *
     * Restores encrypted payloads back to their original
     * plaintext form at the receiving endpoint.
     *
     * @param data Encrypted data string.
     * @param key Decryption key corresponding to the encryption key.
     * @return Decrypted plaintext data.
     */
    static std::string decrypt(const std::string& data,
                               const std::string& key);
};
