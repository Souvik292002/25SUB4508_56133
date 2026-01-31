Problem 2: Automotive – Vehicle Diagnostic Telemetry 
System 
Scenario 
An automotive test lab collects diagnostic data from multiple vehicles during real-time 
testing. 
Requirements 
● Each vehicle sends periodic diagnostic metrics (speed, temperature, RPM). 
● A central server aggregates and stores these metrics. 
● Engineers may request historical data for a specific vehicle. 
● Data volume is high and continuous. 
Constraints / Hints 
● Not all diagnostic packets are equally important 
● Data must be timestamped and grouped per vehicle 
● Server should not block due to slow clients 
● Old data should be archived to files 
Expected Thinking Areas 
● UDP vs TCP for streaming telemetry 
● Circular buffers or queues 
● File rotation strategies 
● STL container selection 
● Handling packet ordering and loss 

🚗 Vehicle Diagnostic Telemetry System
📌 Overview

This project simulates a real-time automotive telemetry system where multiple vehicles send diagnostic data to a central server during testing. The server aggregates, prioritizes, stores, and archives telemetry data while handling high data volume efficiently.

🧩 System Components

Vehicle Client

Sends periodic telemetry (speed, RPM, temperature)

Central Server

Receives telemetry from multiple vehicles

Aggregates and stores data per vehicle

Archives old data to files

Logs errors and critical events

🔄 Why UDP instead of TCP?
TCP	UDP
Reliable, ordered	Fast, lightweight
Blocks on slow clients ❌	No client blocking ✅
High overhead	Low latency
✔ Chosen: UDP

Telemetry is continuous & high frequency

Occasional packet loss is acceptable

Server must never block

🔁 Circular Buffers / Queues
Why?

Telemetry never stops

Unlimited storage causes memory overflow

How?
deque<TelemetryPacket>


Fixed-size buffer per vehicle

Oldest data automatically removed

Prevents memory leaks

📂 File Rotation / Archival Strategy
Problem

Keeping all data in RAM is unsafe

Solution

After N packets, data is written to file

RAM buffer is cleared

File grows incrementally

Benefits

Low memory usage

Historical data preserved

Server remains real-time

📦 STL Container Selection
STL Container	Reason
unordered_map	Fast vehicle lookup (O(1))
deque	         Efficient front removal (circular buffer)
ofstream	      Reliable file handling

⏱ Timestamping & Grouping

Every packet contains:

time(nullptr)


Data grouped by:

vehicleId


This allows:

Time-based analysis

Vehicle-specific diagnostics

⚠ Handling Packet Priority

Critical packets detected using temperature threshold

Logged immediately

Can be extended for alerts

if (temperature > 95) priority = CRITICAL;

📡 Handling Packet Ordering & Loss
Packet Loss

UDP may drop packets

Acceptable for telemetry

Ordering

Timestamp included

Engineers can reorder during analysis

🛑 Error Handling Strategy

No silent failures

All errors:

Logged to telemetry.log

Printed with human-readable messages

Invalid packets safely dropped

✅ Requirements Fulfilled

✔ Periodic telemetry
✔ Central aggregation
✔ Historical data storage
✔ High-volume handling
✔ Non-blocking server
✔ Priority packets
✔ File archival
✔ Robust error handling