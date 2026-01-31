CC = gcc
CFLAGS = -c 
OFLAGS = -o 

SRC = ./src
OBJ = ./obj
BIN = ./bin
INC = ./inc


#Traget1: dependcies
#	cmd to create Traget1
.phony: all clean

$(BIN)/p1: $(SRC)/p1.c
	$(CC) $(OFLAGS) $(BIN)/p1 $(SRC)/p1.c

$(BIN)/p2: $(SRC)/p2.c
	$(CC) $(OFLAGS) $(BIN)/p2 $(SRC)/p2.c


clean:
	@echo "Cleaning in progress"
	rm -rf $(BIN)/*
	rm -rf $(OBJ)/*
	rm -rf a.out
	rm -rf *.o
	@echo "Cleaning Done!"
	
