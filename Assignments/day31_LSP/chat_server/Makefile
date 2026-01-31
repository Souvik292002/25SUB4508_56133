CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
SRC = src/main.cpp src/Server.cpp src/ClientManager.cpp src/Utils.cpp
INC = -Iinclude
BIN = bin/chat_server

all:
	mkdir -p bin
	$(CXX) $(CXXFLAGS) $(INC) $(SRC) -o $(BIN)

clean:
	rm -rf bin
