#include "../include/ATMClient.h"
#include <iostream>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 8080

void ATMClient::run() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = INADDR_ANY;

    connect(sock, (sockaddr*)&addr, sizeof(addr));

    double response;

    // AUTH LOOP
    while (true) {
        int accNo, pin;
        std::cout << "\nEnter Account Number: ";
        std::cin >> accNo;
        std::cout << "Enter PIN: ";
        std::cin >> pin;

        send(sock, &accNo, sizeof(accNo), 0);
        send(sock, &pin, sizeof(pin), 0);

        recv(sock, &response, sizeof(response), 0);

        if (response == -1) {
            std::cout << "❌ Invalid Account or PIN. Try again.\n";
        } else {
            std::cout << "✅ Login Successful\n";
            std::cout << "Current Balance: " << response << "\n";
            break;
        }
    }

    // TRANSACTION LOOP
    while (true) {
        int choice;
        double amount;

        std::cout << "\n1. Deposit\n2. Withdraw\nChoice: ";
        std::cin >> choice;

        if (choice != 1 && choice != 2) {
            std::cout << "❌ Invalid choice. Please select 1 or 2.\n";
            continue;
        }

        std::cout << "Enter amount: ";
        std::cin >> amount;

        if (amount <= 0) {
            std::cout << "❌ Amount must be positive.\n";
            continue;
        }

        send(sock, &choice, sizeof(choice), 0);
        send(sock, &amount, sizeof(amount), 0);

        recv(sock, &response, sizeof(response), 0);

        if (response == -2) {
            std::cout << "❌ Insufficient balance.\n";
        }
        else if (response == -3) {
            std::cout << "❌ Invalid transaction type.\n";
        }
        else {
            std::cout << "✅ Transaction Successful\n";
            std::cout << "Updated Balance: " << response << "\n";
            break;
        }
    }

    close(sock);
}

int main() {
    ATMClient atm;
    atm.run();
    return 0;
}
