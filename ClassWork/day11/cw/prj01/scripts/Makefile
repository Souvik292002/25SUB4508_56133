CC = gcc
CFLAGS = -c
OFLAGS = -o
IFLAGS = -I
LFLAGS = -lm

BIN=./bin
OBJ=./obj
SRC=./src
LIB=./lib
INC=./inc

$(BIN)/calc1: $(OBJ)/app.o $(OBJ)/calc.o
	$(CC) $(OFLAGS) $(BIN)/calc1 $(OBJ)/app.o $(OBJ)/calc.o

$(OBJ)/app.o: $(SRC)/app.c
	$(CC) $(CFLAGS) $(OFLAGS) $(OBJ)/app.o $(SRC)/app.c $(IFLAGS) $(INC)/

$(OBJ)/calc.o: $(SRC)/calc.c
	$(CC) $(CFLAGS) $(OFLAGS) $(OBJ)/calc.o $(SRC)/calc.c $(IFLAGS) $(INC)/

clean:
	@echo "Cleaning in Progress"
	rm -rf $(BIN)/*
	rm -rf $(OBJ)/*
	@echo "Cleaning is Done!"
