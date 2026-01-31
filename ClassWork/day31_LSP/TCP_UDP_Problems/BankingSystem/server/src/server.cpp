#include <iostream>
#include <thread>
#include <string>

// POSIX networking
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>

#include "../include/AccountManager.h"
#include "../include/Logger.h"

#define PORT 8080

// Global objects (shared by all threads)
AccountManager manager("server/data/accounts.txt");
Logger logger("server/logs/server.log");

void handleClient(int clientSocket) {
    int accNo, pin;

    // ---- AUTH PHASE ----
    recv(clientSocket, &accNo, sizeof(accNo), 0);
    recv(clientSocket, &pin, sizeof(pin), 0);

    double balance;
    if (!manager.authenticate(accNo, pin, balance)) {
        logger.log("Authentication failed for Account: " +
                   std::to_string(accNo));

        double err = AUTH_FAILED;
        send(clientSocket, &err, sizeof(err), 0);
        close(clientSocket);
        return;
    }

    // Send current balance
    send(clientSocket, &balance, sizeof(balance), 0);

    // ---- TRANSACTION PHASE ----
    int choice;
    double amount;

    recv(clientSocket, &choice, sizeof(choice), 0);
    recv(clientSocket, &amount, sizeof(amount), 0);

    double updatedBalance;
    int status = manager.processTransaction(
        accNo,
        static_cast<TransactionType>(choice),
        amount,
        updatedBalance
    );

    if (status == 0) {
        send(clientSocket, &updatedBalance, sizeof(updatedBalance), 0);
    } else {
        if (status == INSUFFICIENT_FUNDS)
            logger.log("Insufficient funds | Account: " +
                       std::to_string(accNo));
        else if (status == INVALID_CHOICE)
            logger.log("Invalid transaction choice | Account: " +
                       std::to_string(accNo));

        double err = status;
        send(clientSocket, &err, sizeof(err), 0);
    }

    close(clientSocket);
}

int main() {
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = INADDR_ANY;

    bind(serverSocket, (sockaddr*)&addr, sizeof(addr));
    listen(serverSocket, 10);

    std::cout << "Bank Server running on port " << PORT << std::endl;

    while (true) {
        int clientSocket = accept(serverSocket, nullptr, nullptr);
        std::thread(handleClient, clientSocket).detach();
    }
}
