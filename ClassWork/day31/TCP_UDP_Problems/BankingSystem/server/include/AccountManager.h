#ifndef ACCOUNT_MANAGER_H
#define ACCOUNT_MANAGER_H

#include <unordered_map>
#include <mutex>
#include <string>
#include "Account.h"

enum TransactionType {
    DEPOSIT = 1,
    WITHDRAW = 2
};

enum ServerStatus {
    AUTH_FAILED = -1,
    INSUFFICIENT_FUNDS = -2,
    INVALID_CHOICE = -3
};

class AccountManager {
private:
    std::unordered_map<int, Account> accounts;
    std::mutex accountMutex;
    std::string dataFilePath;

    void persistToFile();

public:
    explicit AccountManager(const std::string& filePath);

    bool authenticate(int accNo, int pin, double &balance);

    int processTransaction(int accNo,
                           TransactionType type,
                           double amount,
                           double &updatedBalance);
};

#endif
