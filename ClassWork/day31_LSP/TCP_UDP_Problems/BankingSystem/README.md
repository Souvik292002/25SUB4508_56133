Problem 1: Banking – Distributed Account Verification 
System 
Scenario 
A bank operates multiple ATM kiosks connected to a central validation server. Each ATM 
must verify account details and balance before processing transactions. 
Requirements 
● The central server maintains account records on disk. 
● Multiple ATM clients send account verification requests concurrently. 
● The server must respond quickly even during peak hours. 
● Failed or invalid requests must be logged persistently. 
● Some operations are critical, while others are informational. 
Constraints / Hints 
● Pax must decide: 
○ Which requests require guaranteed delivery 
○ Which can tolerate occasional packet loss 
● Server must support multiple simultaneous clients 
● Account data is stored in files, not a database 
● Efficient lookup is required 
Expected Thinking Areas 
● TCP vs UDP decision 
● Use of STL containers (map, vector, list) 
● File locking / synchronization 
● Request–response protocol design 
● Error handling and logging

# 🏦 Distributed Banking System (ATM – Server)

## 📌 Overview
This project implements a **Distributed Banking – Account Verification and Transaction System** using **C++ socket programming**.  
Multiple ATM clients communicate concurrently with a centralized banking server to authenticate users, display balances, and perform transactions such as **deposit** and **withdraw**.

The system is designed following **computer networks and operating systems principles**, with emphasis on:
- Client–server architecture
- TCP reliability
- Concurrency
- File-based persistence
- Thread safety
- Robust error handling
- Persistent logging

---

## 🏗️ Architecture

ATM Client ---> TCP ---> Bank Server ---> Account File (Disk)
|
+--> Server Logs (Disk)


### Why TCP?
- Banking operations are **critical**
- Packet loss is unacceptable
- TCP provides **reliability, ordering, and guaranteed delivery**

---

## 📁 Project Structure

BankingSystem/
│
├── bin/
│ ├── bank_server
│ └── atm_client
│
├── server/
│ ├── include/
│ │ ├── Account.h
│ │ ├── AccountManager.h
│ │ └── Logger.h
│ │
│ ├── src/
│ │ ├── AccountManager.cpp
│ │ ├── Logger.cpp
│ │ └── server.cpp
│ │
│ ├── data/
│ │ └── accounts.txt
│ │
│ └── logs/
│ └── server.log
│
├── client/
│ ├── include/
│ │ └── ATMClient.h
│ │
│ └── src/
│ └── atm_client.cpp
│
└── README.md


---

## 📄 Account Data Format

**File:** `server/data/accounts.txt`



<account_number>,<pin>,<balance>


### Example


1001,1234,5000.00
1002,4321,12000.50
1003,9999,300.75


📌 Accounts are **manually managed** by editing this file (as per assignment constraints).

---

## 🔐 Features

### ✅ Authentication
- Account number + PIN verification
- Retry on invalid credentials
- Invalid attempts logged

### 💰 Transactions
- Deposit
- Withdraw
- Insufficient balance checks
- Updated balance returned

### 🧵 Concurrency
- Each ATM client handled in a **separate thread**
- `std::mutex` ensures thread safety

### 🗂️ Persistence
- Account balances stored in files
- All updates written back to disk

### 📄 Logging
- Invalid authentication attempts
- Invalid transaction choices
- Insufficient balance attempts
- Logs stored persistently in `server/logs/server.log`

---

## 🧠 Error Handling & User Experience

| Scenario | Client Message | Server Log |
|--------|---------------|------------|
| Wrong account/PIN | User-friendly retry message | ✅ |
| Invalid menu choice | Prompt to retry | ✅ |
| Insufficient funds | Clear message | ✅ |
| Network issues | Graceful termination | ❌ |

---

## ⚙️ Compilation

Run these commands from the **project root directory**.

### Compile Server
```bash
g++ server/src/server.cpp server/src/AccountManager.cpp server/src/Logger.cpp \
-I server/include -pthread -o bin/bank_server

Compile Client
g++ client/src/atm_client.cpp \
-I client/include -o bin/atm_client

▶️ Running the Application
Terminal 1 – Start Server
./bin/bank_server


Expected output:

Bank Server running on port 8080

Terminal 2 – Run ATM Client
./bin/atm_client


Example interaction:

Enter Account Number: 1001
Enter PIN: 1234
Current Balance: 5000.00

1. Deposit
2. Withdraw
Choice: 1
Enter Amount: 500

Updated Balance: 5500.00

🧪 Concurrent Testing

Open multiple terminals and run:

./bin/atm_client


✔ All clients operate concurrently
✔ Mutex prevents race conditions
✔ Data remains consistent

📜 Sample Server Log

File: server/logs/server.log

[Tue Jan 28 19:42:10 2026]
 Authentication failed for Account: 9999

[Tue Jan 28 19:44:18 2026]
 Insufficient funds | Account: 1001

🎓 Concepts Demonstrated

TCP socket programming

Multithreading (std::thread)

Mutex-based synchronization

File-based persistence

Client–server protocol design

Robust error handling

Logging & auditing

🚀 Future Enhancements (Optional)

Thread pool instead of detached threads

Transaction history per account

Admin authentication

epoll-based scalable server

Message headers & protocol versioning

📌 Summary

This project demonstrates a robust, concurrent, and reliable banking system suitable for:

Computer Networks labs

Operating Systems labs

Mini-projects

Viva and interview discussions

Author:
Souvik Roy
B.Tech CSE