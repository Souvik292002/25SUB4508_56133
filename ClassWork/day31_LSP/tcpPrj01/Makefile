CC = g++

CPPFLAGS = -c -g -Wall
LDFLAGS = -o

INC = ../inc
SRC = ../src
BIN = ../bin
OBJ = ../obj


all: $(BIN)/Server $(BIN)/Client

$(BIN)/Server: $(OBJ)/MainServer.o $(OBJ)/common.o $(OBJ)/Emp.o
	$(CC) $(LDFLAGS) $(BIN)/Server $(OBJ)/MainServer.o $(OBJ)/common.o $(OBJ)/Emp.o

$(OBJ)/MainServer.o: $(SRC)/MainServer.cpp
	$(CC) $(CPPFLAGS) $(SRC)/MainServer.cpp -I $(INC)
	mv *.o $(OBJ)/

$(OBJ)/common.o: $(SRC)/common.cpp
	$(CC) $(CPPFLAGS) $(SRC)/common.cpp -I $(INC)
	mv *.o $(OBJ)/

$(OBJ)/Emp.o: $(SRC)/Emp.cpp
	$(CC) $(CPPFLAGS) $(SRC)/Emp.cpp -I $(INC)
	mv *.o $(OBJ)/

$(BIN)/Client: $(OBJ)/MainClient.o $(OBJ)/common.o $(OBJ)/Emp.o
	$(CC) $(LDFLAGS) $(BIN)/Client $(OBJ)/MainClient.o $(OBJ)/common.o $(OBJ)/Emp.o

$(OBJ)/MainClient.o: $(SRC)/MainClient.cpp
	$(CC) $(CPPFLAGS) $(SRC)/MainClient.cpp -I $(INC)
	mv *.o $(OBJ)/

clean:
	rm -f a.out Server Client
	rm -f $(BIN)/Server $(BIN)/Client
	rm -f $(OBJ)/*.o
	@echo "Cleaning Done!"