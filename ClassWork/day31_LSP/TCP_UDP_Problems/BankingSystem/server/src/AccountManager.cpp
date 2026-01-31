#include "../include/AccountManager.h"
#include <fstream>
#include <sstream>

AccountManager::AccountManager(const std::string& filePath)
    : dataFilePath(filePath) {

    std::ifstream file(filePath);
    std::string line;

    while (getline(file, line)) {
        std::stringstream ss(line);
        int acc, pin;
        double bal;
        char comma;

        ss >> acc >> comma >> pin >> comma >> bal;
        accounts[acc] = { pin, bal };
    }
}

void AccountManager::persistToFile() {
    std::ofstream file(dataFilePath, std::ios::trunc);
    for (auto &entry : accounts) {
        file << entry.first << ","
             << entry.second.pin << ","
             << entry.second.balance << "\n";
    }
}

bool AccountManager::authenticate(int accNo, int pin, double &balance) {
    std::lock_guard<std::mutex> lock(accountMutex);

    auto it = accounts.find(accNo);
    if (it == accounts.end() || it->second.pin != pin)
        return false;

    balance = it->second.balance;
    return true;
}

int AccountManager::processTransaction(int accNo,
                                       TransactionType type,
                                       double amount,
                                       double &updatedBalance) {
    std::lock_guard<std::mutex> lock(accountMutex);

    auto &account = accounts[accNo];

    if (type == WITHDRAW) {
        if (account.balance < amount)
            return INSUFFICIENT_FUNDS;
        account.balance -= amount;
    }
    else if (type == DEPOSIT) {
        account.balance += amount;
    }
    else {
        return INVALID_CHOICE;
    }

    updatedBalance = account.balance;
    persistToFile();
    return 0;
}
