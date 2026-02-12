#pragma once

/*
 * ============================================================
 *  File: CryptoUtil.h
 *  Module: ECSBF Cryptographic Utilities
 * ------------------------------------------------------------
 *  Description:
 *  This header defines the CryptoUtil utility class, which
 *  provides cryptographic helper functions used within the
 *  Enterprise Concurrent Signal Broadcast Framework (ECSBF).
 *
 *  The utilities encapsulate encryption and decryption
 *  operations applied to data packets prior to transmission
 *  and after reception, ensuring confidentiality of signals
 *  exchanged across the distributed node network.
 *
 *  This module supports secure end-to-end communication
 *  without exposing cryptographic implementation details
 *  to higher-level components.
 * ============================================================
 */

#include <string>

/*
 * ------------------------------------------------------------
 *  Class: CryptoUtil
 * ------------------------------------------------------------
 *  Responsibility:
 *  Provides stateless cryptographic operations for protecting
 *  data exchanged between ECSBF Core Engine and endpoint nodes.
 *
 *  Design Characteristics:
 *   - Static utility interface
 *   - No internal state persistence
 *   - Cryptographic abstraction boundary
 *
 *  This design allows cryptographic algorithms or libraries
 *  to be upgraded or replaced without impacting calling code.
 * ------------------------------------------------------------
 */
class CryptoUtil {
public:
    /*
     * Encrypts a plaintext data payload.
     *
     * Parameters:
     *  - data : Plaintext data to be encrypted
     *
     * Returns:
     *  - Encrypted representation of the input data
     *
     * Intended Use:
     *  - Securing outbound signals
     *  - Protecting sensitive control messages
     */
    static std::string encrypt(const std::string& data);

    /*
     * Decrypts an encrypted data payload.
     *
     * Parameters:
     *  - data : Encrypted data to be decrypted
     *
     * Returns:
     *  - Decrypted plaintext representation
     *
     * Intended Use:
     *  - Processing inbound secure signals
     *  - Restoring original message content
     */
    static std::string decrypt(const std::string& data);
};
