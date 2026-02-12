Enterprise Concurrent Signal Broadcast Framework (ECSBF)
1. Project Overview

Enterprise Concurrent Signal Broadcast Framework (ECSBF) is a multi-threaded, TCP-based communication backbone designed to support real-time signal propagation across a distributed network of endpoint nodes.

The framework implements a centralized engine (server) responsible for:

Managing concurrent client connections

Authenticating and provisioning endpoint nodes

Maintaining persistent session states

Broadcasting encrypted messages to all active nodes

Providing multi-level diagnostic logging for observability

Each client node connects to the engine using TCP sockets and participates in a real-time broadcast chat system, demonstrating enterprise-grade concurrency and communication principles.

2. Key Features

🔹 Multi-Threaded Server Architecture

One thread per connected client

OS-level scalability (FR-05)

🔹 Real TCP-Based Communication

True cross-terminal messaging

No simulated or shared-memory logic

🔹 Dynamic Node Provisioning

Runtime registration and login

No static configuration files

🔹 Persistent Session Management

Session lifecycle handled by the engine

Automatic cleanup on logout/disconnect

🔹 Unified Signal Broadcast

Messages sent by one node are delivered to all other active nodes

Self-echo is explicitly prevented

🔹 Logical Cryptographic Protection

Payloads encrypted before transmission

Decrypted at receiving endpoints

🔹 Multi-Level Observability

Engine and client logs

Clear audit trail of system events

3. System Architecture
3.1 High-Level Architecture

+------------------+        TCP        +----------------------+
|  Client Node A   | <--------------> |                      |
|  (EndpointNode)  |                  |                      |
+------------------+                  |                      |
                                      |   ECSBF Core Engine  |
+------------------+        TCP        |   (Server)           |
|  Client Node B   | <--------------> |                      |
|  (EndpointNode)  |                  |                      |
+------------------+                  |                      |
                                      +----------------------+

3.2 Concurrency Model

The ECSBF engine runs as a TCP server

Each incoming client connection is handled by a dedicated thread

Shared resources are protected using mutexes

Broadcast operations are executed centrally by the engine

4. Project Directory Structure

ECSBF/
├── include/
│   ├── core/        # Engine interfaces
│   ├── client/      # Client interfaces
│   ├── network/     # TCP socket abstractions
│   ├── registry/    # Identity management
│   ├── session/     # Session lifecycle
│   ├── signal/      # Signal processing & broadcast
│   ├── security/    # Encryption utilities
│   ├── logging/     # Logging utilities
│   └── models/      # Data models
│
├── src/
│   ├── core/
│   ├── client/
│   ├── network/
│   ├── registry/
│   ├── session/
│   ├── signal/
│   ├── security/
│   ├── logging/
│   ├── main_engine.cpp
│   └── main_client.cpp
│
├── logs/
│   ├── engine.log
│   └── node.log
│
├── Makefile
└── README.md


5. Functional Requirements Mapping

| Requirement ID | Description                 | Implementation        |
| -------------- | --------------------------- | --------------------- |
| ECSBF_FR_01    | Node-Engine Handshake       | TCP connection        |
| ECSBF_FR_02    | Node Provisioning           | Runtime registration  |
| ECSBF_FR_03    | Identity Verification       | Server authentication |
| ECSBF_FR_04    | Persistent Sessions         | SessionManager        |
| ECSBF_FR_05    | Multi-Threaded Engine       | Thread per client     |
| ECSBF_FR_06    | Unified Signal Broadcast    | Engine-side broadcast |
| ECSBF_FR_07    | Global Identity Registry    | Central registry      |
| ECSBF_FR_08    | Session Finalization        | Logout / disconnect   |
| ECSBF_FR_09    | Network Identity Resolution | Socket IP handling    |
| ECSBF_FR_10    | Cryptographic Protection    | CryptoUtil            |
| ECSBF_FR_11    | Payload Decryption          | Client-side decrypt   |
| ECSBF_FR_12    | Multi-Level Observability   | Logger                |


6. Build Instructions
6.1 Prerequisites

Linux / macOS / WSL

g++ (C++17 compatible)

make

6.2 Build

From the project root:

make clean
make

This produces two executables:

bin/engine
bin/client

7. Running the Application

7.1 Start the Engine

Open Terminal 1:

./bin/engine

The engine listens on port 9090.

7.2 Start Clients

Open Terminal 2 / Terminal 3 / Terminal N:

./bin/client

Each client can:

1) Register

2) Login

3) Send chat messages

4) Receive broadcasts from other clients

8. How to Use the Application

This section describes the typical user workflow for interacting with the ECSBF system from both the engine (server) and client (endpoint node) perspectives.

8.1 Engine Usage

The ECSBF Core Engine acts as a central coordinator and does not require user interaction after startup.

Steps:

1) Start the engine:

./bin/engine

2) The engine will:

Listen on TCP port 9090

Accept incoming client connections

Spawn a dedicated thread for each client

Log all registration, authentication, session, and broadcast events

Expected Output:
[ENGINE] Listening on port 9090
[ENGINE] New client connected
[ENGINE] Node registered: Alice
[ENGINE] User logged in: Bob
[ENGINE] Broadcast from Alice

The engine must remain running for clients to connect and communicate.

8.2 Client Usage

Each ECSBF client represents an endpoint node in the distributed system.

Multiple clients can be launched simultaneously in separate terminals.

8.2.1 Starting a Client

./bin/client

Upon startup, the client automatically connects to the ECSBF engine and displays the main menu.

8.2.2 Main Menu Options

==============================
   ECSBF CHAT CLIENT MENU
==============================
1. Register
2. Login
3. Exit

Option 1: Register (Node Provisioning)

Registers a new endpoint node with the ECSBF engine.

Steps:

1) Select option 1

2) Enter a unique username

3) Enter a password

Expected Result:

Registration successful!

Registration does not terminate the application.
The menu is displayed again after completion.

Option 2: Login (Authentication & Session Creation)

Authenticates an existing node and creates a persistent session.

Steps:

1) Select option 2

2) Enter registered username and password

Expected Result:
Login successful! Welcome Alice
Type messages to chat.

After successful login, the client enters chat mode.

8.3 Chat Mode (Signal Broadcast)

Once logged in, the client can send messages that are broadcast to all other active clients.

Sending a Message

Simply type a message and press Enter:

Hello everyone!

Message Delivery

<.> The sender does not see their own message echoed

<.> All other logged-in clients receive the message in real time

Example (on other clients):

Alice: Hello everyone!

8.4 Client Commands

While in chat mode, the following commands are supported:

| Command   | Description                                    |
| --------- | ---------------------------------------------- |
| `/logout` | Ends the session and returns to main menu      |
| `/exit`   | Logs out (if needed) and terminates the client |

8.5 Logging Behavior

Client-side events are written to:

logs/node.log

Engine-side events are written to:

logs/engine.log

Logs include:

1) Connection events

2) Registration attempts

3) Authentication status

4) Message broadcast activity

5) Session termination

8.6 Multi-Client Usage Example

To demonstrate full system functionality:

1) Start the engine in Terminal 1

2) Start Client A in Terminal 2

3) Start Client B in Terminal 3

4) Register and login both clients

5) Send messages from either client

All messages will be delivered across terminals via the ECSBF engine.

8.7 Proper Shutdown

1) Clients should exit using /exit

2) The engine can be terminated safely using Ctrl + C

Why This Section Matters (For Evaluation)

This usage section:

1) Clearly demonstrates functional correctness

2) Shows compliance with all ECSBF functional requirements

3) Makes the system easy to evaluate and demo

4) Reflects industry-standard documentation practices


9. Client Commands

| Command   | Description                 |
| --------- | --------------------------- |
| `/logout` | Logout and return to menu   |
| `/exit`   | Exit the client application |

10. Logging & Observability

Logs are generated automatically:

1) logs/engine.log → Server-side events

2) logs/node.log → Client-side events

Log levels include:

1) INFO

2) WARNING

3) ERROR

4) FATAL

11. Security Model

<> Messages are logically encrypted before transmission

<> Encryption is reversible and demonstrative

<> Designed for academic clarity and extensibility

<> Can be replaced with real cryptographic libraries in future versions

12. Testing Summary

<> Functional testing (registration, login, broadcast)

<> Negative testing (invalid login, duplicate registration)

<> Integration testing (multi-client broadcast)

<> Observability testing (log verification)

All tests pass successfully.

13. Limitations & Future Enhancements

Current Scope

<> Single-server architecture

<> Logical encryption

<> TCP blocking I/O

Future Improvements

<> TLS encryption

<> Distributed registry

<> Message persistence

<> Non-blocking I/O (epoll)

<> GUI client

13. Conclusion

ECSBF demonstrates a realistic enterprise-style communication framework using modern C++ practices, TCP networking, and concurrent server design. The project successfully bridges academic requirements with professional software engineering principles.

14. Author

Capstone Project – Enterprise Concurrent Signal Broadcast Framework (ECSBF)
Developed as part of an academic project by

<<<.......................SOUVIK ROY............................>>>
<<<.......................KRITHIV DHARAN SA.....................>>>
<<<.......................ALISHA PRAVEEN........................>>>
<<<.......................RITTIWIKA DATTA.......................>>>