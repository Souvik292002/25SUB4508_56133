Enterprise Concurrent Signal Broadcast Framework (ECSBF)

📌 Project Overview:

The Enterprise Concurrent Signal Broadcast Framework (ECSBF) is a high-performance, centralized-engine distributed communication framework designed for secure, real-time signal propagation across multiple networked nodes.

ECSBF enables authenticated endpoint nodes to establish persistent sessions with a centralized Core Engine, transmit encrypted messages, and receive broadcasted signals concurrently. The framework is built with a strong emphasis on scalability, security, fault tolerance, and observability.

🎯 Core Objectives:

Secure node registration and authentication

Persistent session lifecycle management

Multi-threaded concurrent signal processing

Encrypted payload transmission

Unified broadcast to all active nodes

Structured multi-level diagnostic logging

🏗 Architectural Model:

ECSBF follows a centralized broadcast architecture:

A Core Engine manages identity verification, session control, encryption keys, and concurrent message handling.

Multiple Client Nodes connect via persistent TCP sessions.

Messages from any node are securely decrypted, processed, and re-encrypted before being broadcasted to all other active nodes.

This architecture ensures controlled access, traceability, and reliable communication in distributed environments.

🚀 Key Features:
🔐 Secure Node Registration & Authentication

Provisioned node management via Global Identity Registry

Mandatory identity verification before session establishment

Controlled access to Engine services

🔄 Persistent Session Management

Stateful session lifecycle handling

Automatic session restoration on reconnection

Graceful session invalidation on disconnect

⚡ Concurrent Signal Processing:

Multi-threaded Engine architecture

Parallel handling of multiple node connections

High-throughput message processing

📡 Unified Signal Broadcasting:

Automatic broadcast of messages to all active nodes

Source traceability using numeric node identifiers

Session-aware message routing

🔒 Encrypted Communication:

Session-based symmetric encryption

Secure decryption at receiving endpoints

Protected payload transmission over TCP/IP

📊 Multi-Level Diagnostic Logging:

Supports FATAL, INFO, WARNING, DEBUG levels

Thread-safe logging implementation

Automatic log rotation (size-based)

Structured timestamped log format

🧩 Modular & Scalable Design:

Clean separation of core, client, networking, logging, registry, and security modules

Portable across Linux and Windows (C++17 compliant)

Easily extensible for advanced cryptographic or protocol upgrades

🏗 System Architecture:

ECSBF follows a centralized broadcast architecture built around a multi-threaded Core Engine and multiple distributed Client Nodes.

🧠 Core Engine:

The ECSBF Core Engine acts as the authoritative control unit and is responsible for:

Node registration and authentication

Persistent session lifecycle management

Session key generation and encryption handling

Concurrent message processing (thread-per-client model)

Broadcasting decrypted messages to all active nodes

Multi-level diagnostic logging

The Engine maintains:

A Global Identity Registry

Active session mappings

Socket-to-node associations

Session encryption keys

🖥 Client Nodes:

Each Client Node:

Establishes a TCP connection with the Engine

Registers or authenticates using credentials

Receives a session-specific encryption key

Encrypts outgoing messages before transmission

Decrypts broadcasted messages upon receipt

Clients maintain a persistent connection and run a background listener thread for real-time message handling.

🔐 Communication Flow:

Client connects to Engine (TCP handshake)

Node registers or logs in

Engine verifies identity via Identity Registry

Engine generates and assigns a session key

Client sends encrypted message

Engine decrypts → processes → re-encrypts

Engine broadcasts to all active nodes

📦 High-Level Architecture Model:

           +----------------------+
           |    ECSBF Core Engine |
           |----------------------|
           | Identity Registry    |
           | Session Manager      |
           | Concurrency Engine   |
           | Logger               |
           +----------+-----------+
                      |
        -----------------------------------
        |                |               |
+--------------+ +--------------+ +--------------+
| Client Node  | | Client Node  | | Client Node  |
| (Encrypted)  | | (Encrypted)  | | (Encrypted)  |
+--------------+ +--------------+ +--------------+

⚙ Architectural Characteristics:

Centralized control with distributed endpoints

Thread-safe multi-client handling

Session-aware communication model

Encrypted message lifecycle

Fault-tolerant session management

📂 Project Directory Structure:

The ECSBF project follows a modular and layered directory structure to ensure separation of concerns, maintainability, and scalability.

ECSBF/
│
├── apps/
│   ├── engine/
│   │   └── main_engine.cpp        # Engine entry point
│   └── client/
│       └── main_client.cpp        # Client entry point
│
├── include/
│   ├── core/                      # Core Engine headers
│   ├── client/                    # Client headers
│   ├── logging/                   # Logger headers
│   ├── network/                   # Network utilities
│   ├── registry/                  # Identity registry headers
│   ├── security/                  # Crypto & identity headers
│   └── session/                   # Session management headers
│
├── src/
│   ├── core/                      # Core Engine implementation
│   ├── client/                    # Client implementation
│   ├── logging/                   # Logger implementation
│   ├── network/                   # Network utilities implementation
│   ├── registry/                  # Identity registry implementation
│   ├── security/                  # Cryptographic utilities
│   └── session/                   # Session lifecycle implementation
│
├── logs/                          # Auto-generated log files
│
├── Makefile                       # Build configuration
└── README.md                      # Project documentation

🧩 Structural Design Principles:

Modular Architecture – Clear separation between core engine, client, networking, security, and logging.

Layered Organization – include/ for headers, src/ for implementations.

Application Isolation – Separate entry points for Engine and Client.

Scalability Ready – Easy extension for additional protocols or security enhancements.

Clean Build System – Managed via centralized Makefile.

📋 Functional Requirements Mapping:

The following table maps the implemented system behavior to the defined ECSBF Functional Requirements (FR):

| ID        | Requirement Description                     | Implementation Component                                     |
| --------- | ------------------------------------------- | ------------------------------------------------------------ |
| **FR-01** | Secure handshake between Node and Engine    | `Client::connectToEngine()`                                  |
| **FR-02** | Node must be provisioned before access      | `IdentityRegistry::registerNode()`                           |
| **FR-03** | Mandatory identity verification             | `IdentityRegistry::authenticate()`                           |
| **FR-04** | Persistent session management               | `Session` class + `sessions` map in Engine                   |
| **FR-05** | Multi-threaded concurrent signal processing | Thread-per-client model in `ECSBF_CoreEngine::startEngine()` |
| **FR-06** | Broadcast signals to all active nodes       | Broadcast loop inside Engine message handler                 |
| **FR-07** | Maintain Global Identity Registry           | `IdentityRegistry` internal `nodeDB` map                     |
| **FR-08** | Session termination and cleanup             | `Session::invalidate()` + socket cleanup logic               |
| **FR-09** | Identity resolution (node traceability)     | `nodeNumericId` mapping in Engine                            |
| **FR-10** | Encrypt sensitive identifiers and payload   | `CryptoUtil::encrypt()`                                      |
| **FR-11** | Secure payload decryption at endpoints      | `CryptoUtil::decrypt()`                                      |
| **FR-12** | Multi-level diagnostic logging              | `Logger` (FATAL, INFO, WARNING, DEBUG)                       |

🎯 Requirement Traceability:

Each functional requirement is directly implemented in a dedicated module.

Core Engine enforces security, session control, and broadcasting logic.

Client enforces encryption before transmission.

Logger ensures runtime observability.

IdentityRegistry ensures controlled access enforcement.

This structured mapping ensures clear traceability between the SRS specification and the implementation.

🛠 Build Instructions:

ECSBF uses a centralized Makefile for compiling both the Engine and Client applications.

✅ Prerequisites:

g++ (C++17 compatible)

GNU Make

Linux or Windows (with POSIX compatibility layer such as WSL for socket APIs)

Verify compiler version:
g++ --version

🔧 Build All Components:

Compile both Engine and Client:
make

This generates:
apps/engine/engine
apps/client/client

⚙ Build Individually:

Build Engine only:
make engine

Build Client only:
make client

🧹 Clean Binaries:

Remove compiled executables:
make clean

🔁 Rebuild from Scratch:

Clean and rebuild everything:
make rebuild

📌 Compiler Configuration:

Standard: C++17

Warnings Enabled: -Wall

Modular include structure via -Iinclude/...

The build system ensures modular compilation and consistent output structure for both Engine and Client components.

▶️ Running the Application:

ECSBF consists of two independent executables:

Core Engine (Server)

Client Node (Endpoint)

The Engine must be started before launching any Client instances.

🧠 Step 1: Start the Engine:
./apps/engine/engine

Expected behavior:

Engine initializes logging

Binds to configured port

Starts listening for incoming node connections

Waits for client authentication requests

🖥 Step 2: Start a Client

In a separate terminal:
./apps/client/client


The client will display an interactive menu:
========= ECSBF NODE =========
1. Register
2. Login
3. Exit

🔐 Registration Flow:

Choose Register

Provide a UserID (alphanumeric only)

Provide a Password

Upon success, login to begin communication

🔑 Login Flow:

Choose Login

Enter registered credentials

On success:

A session key is assigned

Secure encrypted communication begins

Client enters chat mode

💬 Chat Mode:

Type messages to broadcast to all active nodes

Messages are:

Encrypted before transmission

Decrypted and processed by Engine

Re-encrypted for each recipient

Type exit to disconnect

📊 Logs:

Log files are automatically generated in:
logs/

Includes:
engine.log
<nodeId>.log
client.log

Logs support multiple levels: FATAL, INFO, WARNING, DEBUG.

⚠ Important Notes:

Engine must be running before starting clients.

Multiple client instances can be launched simultaneously.

Each client runs in a persistent session until disconnected.


🧭 How to Use the Application:

This section provides a practical walkthrough of using ECSBF after building and launching the Engine and Client.

1️⃣ Start the Core Engine:
./apps/engine/engine


The Engine initializes logging.

It binds to the configured port.

It begins listening for client connections.

Keep this terminal running.

2️⃣ Launch a Client Node:

Open a new terminal:
./apps/client/client


You will see:
========= ECSBF NODE =========
1. Register
2. Login
3. Exit

3️⃣ Register a New Node:

Choose:
1


Then provide:

UserID (alphanumeric only)

Password

If successful:

REGISTER_SUCCESS
Please login to continue.


Registration adds the node to the Global Identity Registry.

4️⃣ Login to Start a Session:

Choose:
2


Provide:

Registered UserID

Password

On success:
LOGIN_SUCCESS
You can now chat.
Type 'exit' to quit.


At this point:

A secure session is created

A session encryption key is assigned

Persistent communication begins

5️⃣ Send Messages:

Once logged in:

Type any message and press Enter

The message will be:

Encrypted by the client

Decrypted and processed by the Engine

Re-encrypted and broadcast to all active nodes

To test broadcasting:

Run multiple clients

Login with different accounts

Send messages from one client

Observe real-time delivery in others

6️⃣ Exit the Application:

To disconnect:
exit


This triggers:

Graceful session termination

Socket shutdown

Session invalidation on the Engine

🔐 Security Behavior:

Only registered nodes can log in.

Authentication is mandatory.

All chat messages are encrypted during transmission.

Each session has its own encryption key.

📊 Monitoring Logs:

All logs are stored in:
logs/


You can monitor activity using:
tail -f logs/engine.log


The application supports multiple concurrent nodes and real-time encrypted broadcasting.


🖥 Client Commands:

The ECSBF Client operates through a simple interactive console interface.

📋 Startup Menu Commands:

When the client starts, the following options are available:

1. Register
2. Login
3. Exit

Command	 Description
1	       Register a new node in the Global Identity Registry
2	       Authenticate and start a secure session
3	       Exit the application

🔐 Registration Command:

Option: 1

Prompts:

Enter UserID

Enter Password

Rules:

UserID must be alphanumeric only

Empty or invalid input is rejected

Successful response:
REGISTER_SUCCESS

🔑 Login Command:

Option: 2

Prompts:

Enter UserID

Enter Password

On success:
LOGIN_SUCCESS
You can now chat.
Type 'exit' to quit.

This initiates:

Session creation

Session key assignment

Encrypted communication mode

💬 Chat Mode Commands:

Once logged in, any typed text is treated as a message.

Input	      Behavior
<any text>	Encrypted and broadcast to all active nodes
exit	      Gracefully disconnect and terminate session

🔄 Runtime Behavior:

During chat mode:

Incoming messages are automatically decrypted and displayed.

The client runs a background listener thread.

Communication continues until exit is entered.

⚠ Input Validation:

Non-numeric menu input is rejected.

UserID must contain only letters and numbers.

Invalid login attempts are denied.

The client provides a secure, session-based, encrypted communication interface for interacting with the ECSBF Core Engine.


📊 Logging & Observability:

ECSBF includes a centralized, thread-safe logging subsystem designed to support operational monitoring, debugging, and traceability.

🧠 Logging Architecture:

The framework uses a Singleton Logger to ensure:

Centralized log management

Thread-safe write operations

Structured, timestamped log entries

Runtime-configurable log levels:

Logs are automatically stored inside:
logs/

📝 Log Levels:

ECSBF supports four severity levels:

Level 	Description
FATAL	   Critical system errors that may halt execution
INFO	   Normal operational events
WARNING	Abnormal conditions requiring attention
DEBUG	   Detailed diagnostic information

Log filtering is controlled via:

logger.setLogLevel(DEBUG);

📁 Log Files:

The system generates:

engine.log – Core Engine events

client.log – Client runtime events

<nodeId>.log – Per-node activity logs

Each log entry follows this format:
[YYYY-MM-DD HH:MM:SS] [LEVEL] Message

🔄 Automatic Log Rotation:

To prevent uncontrolled log growth:

Maximum file size: 5 MB per log file

When exceeded:

Current file is rotated

Backup created as .1

New log file opened automatically

This ensures stable disk usage during long-running sessions.

🔍 Observability Features:

Real-time monitoring via log inspection

Per-node traceability

Encrypted/decrypted message tracking (DEBUG level)

Session lifecycle logging

Authentication and connection events

You can monitor logs in real time using:
tail -f logs/engine.log

🛡 Operational Benefits:

Supports debugging in concurrent environments
Provides audit trail for security-sensitive operations
Enables production-level runtime visibility
Assists in fault isolation and performance analysis

ECSBF’s logging system ensures complete runtime transparency while maintaining thread safety and scalability.


🔐 Security Model:

ECSBF is designed with a layered security model to ensure controlled access, encrypted communication, and session integrity across distributed nodes.

🛡 1. Controlled Access (Identity Enforcement):

Only provisioned nodes can participate in the system.

All clients must:

Register (provisioning phase)

Authenticate before session establishment

Authentication is validated against the Global Identity Registry.

This enforces strict access control and prevents unauthorized signal injection.

🔑 2. Mandatory Authentication:

Login requires valid credentials.

Failed authentication attempts are:

Logged

Rejected

No session is created without successful verification.

This ensures only trusted nodes can communicate with the Engine.

🔄 3. Session-Based Security:

Each successful login results in:

Session creation

Session state tracking

Assignment of a session encryption key

Sessions are invalidated upon disconnection.

This maintains secure and controlled communication lifecycle management.

🔒 4. Encrypted Communication:

All chat messages are encrypted before transmission.

The Engine decrypts incoming payloads.

Messages are re-encrypted individually for each recipient.

Communication occurs over persistent TCP connections.

Encryption protects:

Signal payloads

Session-level communication

🧩 5. Isolation Between Nodes:

Each node has its own session key.

Messages are re-encrypted per recipient.

No node can directly access another node’s session data.

This ensures message confidentiality within broadcast operations.

📊 6. Secure Logging Practices:

Logs do not expose raw credentials.

Authentication failures are recorded for auditability.

Debug logs provide encrypted/decrypted trace visibility when enabled.

⚠ Security Considerations:

Current encryption uses a demonstration XOR-based mechanism.

For production-grade deployment, it is recommended to:

Replace with a standard cryptographic algorithm (e.g., AES)

Store passwords in hashed form

Introduce secure key exchange mechanisms

🧠 Security Design Principles:

Least privilege access model

Session isolation

Encrypted transport

Centralized identity validation

Full audit traceability

The ECSBF security model ensures secure, traceable, and controlled distributed communication across all active nodes.

🧪 Testing Summary:

ECSBF was tested to validate functional correctness, concurrency handling, session lifecycle integrity, and secure communication behavior.

✅ Functional Testing:

The following functional scenarios were validated:

✔ Node registration and credential storage

✔ Successful and failed login attempts

✔ Session creation and restoration

✔ Graceful session termination on disconnect

✔ Broadcast message delivery to all active nodes

✔ Encrypted message transmission and decryption

✔ Per-node log generation

All Functional Requirements (FR-01 to FR-12) were verified through runtime execution.

🔄 Concurrency Testing:

Multiple client instances were launched simultaneously.

Parallel message sending was tested across active nodes.

Engine thread-per-client model successfully handled concurrent communication.

No race conditions observed during message broadcasting.

🔐 Security Validation:

Unregistered nodes were denied login.

Invalid credentials were correctly rejected.

Encrypted messages were verified at transmission and reception.

Session invalidation occurred correctly after disconnection.

📊 Logging Verification:

All major system events were logged:

Engine startup

Client connection

Registration and login

Session key generation

Message transmission

Client disconnection

Log rotation mechanism was validated under file size thresholds.

⚙ Stability Testing:

Engine remained stable under multiple client sessions.

Controlled shutdown sequence executed correctly.

Socket cleanup and session invalidation performed without resource leakage.

📌 Test Environment:

C++17 (g++)

Linux environment (POSIX socket APIs)

Multi-terminal client execution

Makefile-based build system

ECSBF successfully demonstrates secure, concurrent, session-based broadcast communication under multi-client runtime conditions.

⚠ Limitations & Future Enhancements:

While ECSBF demonstrates a secure, concurrent broadcast framework, certain limitations exist in the current implementation. The following enhancements are recommended for production-grade deployment.

⚠ Current Limitations:
🔐 1. Demonstration-Level Encryption:

Uses a simple XOR-based symmetric encryption model.

Not suitable for high-security production environments.

🔑 2. Plaintext Credential Storage:

Passwords are stored without hashing.

Lacks salting and secure credential management.

🌐 3. Basic Socket Handling:

Uses blocking sockets.

No timeout or advanced connection management.

No TLS/SSL transport layer security.

📦 4. In-Memory Identity Registry:

Identity data is not persisted to a database.

Registry is reset on Engine restart.

📊 5. Limited Monitoring Metrics:

No real-time metrics dashboard.

No performance analytics or throughput monitoring.

🧵 6. Thread-per-Client Model:

While functional, it may not scale efficiently for very high connection counts.

No thread pool or event-driven architecture implemented.

🚀 Future Enhancements
🔒 1. Production-Grade Cryptography:

Replace XOR encryption with AES or similar standard.

Implement secure key exchange mechanism.

Introduce TLS-based encrypted transport.

🔑 2. Secure Credential Management:

Store hashed passwords (e.g., bcrypt, SHA-256 with salt).

Add authentication attempt throttling.

🗄 3. Persistent Identity Storage:

Integrate database support (e.g., SQLite, PostgreSQL).

Enable persistent registry across restarts.

📈 4. Observability & Monitoring:

Add structured logging (JSON format).

Integrate monitoring tools (Prometheus, ELK stack).

Provide runtime metrics dashboard.

⚙ 5. Scalable Concurrency Model:

Implement thread pool architecture.

Explore event-driven model (epoll / select).

Support horizontal scaling via distributed engine instances.

🌍 6. Protocol Enhancements:

Add support for message types (private messaging, channels).

Introduce message acknowledgment system.

Add rate limiting per node.

🧩 7. Web or GUI Interface:

Build administrative dashboard.

Provide web-based client interface.

🎯 Long-Term Vision:

ECSBF can evolve into a:

Secure distributed messaging platform

Enterprise-grade event broadcast system

Real-time communication backbone

Microservice signal distribution framework

The current implementation provides a solid architectural foundation for secure, concurrent, session-based broadcast communication, ready for advanced enterprise-level enhancements.

🏁 Conclusion:

The Enterprise Concurrent Signal Broadcast Framework (ECSBF) successfully demonstrates a secure, multi-threaded, session-based broadcast communication system built using modern C++ (C++17).

The framework integrates:

Centralized identity verification

Persistent session management

Concurrent multi-client handling

Encrypted message transmission

Structured multi-level logging

Modular and scalable architecture

ECSBF fulfills all defined functional requirements (FR-01 to FR-12) and provides clear traceability between system design and implementation.

🎯 Key Achievements:

Secure authentication-driven communication model

Thread-safe broadcast engine

Per-session encryption handling

Clean modular separation of concerns

Production-style logging and observability

Portable and extensible codebase

🚀 Final Remark:

ECSBF establishes a strong architectural foundation for building secure distributed communication systems. With further enhancements in cryptography, persistence, and scalability, it can evolve into a production-ready enterprise broadcast platform.

👥 Authors:

Capstone Project – Enterprise Concurrent Signal Broadcast Framework (ECSBF)
Developed as part of an academic project by

<<<.......................SOUVIK ROY............................>>>
<<<.......................KRITHIV DHARAN SA.....................>>>
<<<.......................ALISHA PRAVEEN........................>>>
<<<.......................RITTIWIKA DATTA.......................>>>

📌 Project Contributions

The team collaboratively worked on:

System Architecture Design
Software Requirements Specification (SRS)
Core Engine Implementation
Client Module Development
Security & Encryption Model
Logging & Observability Framework
Testing & Documentation