# Concurrent Chat Server using select()

## Protocol Used
TCP (Transmission Control Protocol)

### Why TCP?
- Reliable communication
- Guaranteed message delivery
- Maintains client connection state
- Suitable for chat applications where message loss is unacceptable

## Concurrency Model
- Uses `select()` system call
- Single-threaded, event-driven
- Handles multiple clients simultaneously
- Efficient for moderate number of clients

## Broadcasting Logic
- When a client sends a message
- Server forwards it to all connected clients
- Sender does NOT receive their own message

## Folder Structure
- include/ → Header files
- src/     → Implementation (.cpp)
- bin/     → Compiled binary

## How to Build
```bash
make
