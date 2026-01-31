CC := gcc
CFLAGS := -c
OFLAGS := -o
IFLAGS := -I
LFLAGS := -lm

BIN :=./bin
OBJ :=./obj
SRC :=./src
LIB :=./lib
INC :=./inc

$(BIN)/app: $(OBJ)/stEmp.o $(OBJ)/stEmp2.o $(OBJ)/getDetails.o $(OBJ)/p1.o 
	$(CC) $(OFLAGS) $(BIN)/app1 $(OBJ)/p1.o $(OBJ)/stEmp.o $(OBJ)/stEmp2.o $(OBJ)/getDetails.o

$(OBJ)/p1.o: $(SRC)/p1.c
	$(CC) $(CFLAGS) $(OFLAGS) $(OBJ)/p1.o $(SRC)/p1.c $(IFLAGS) $(INC)/

$(OBJ)/stEmp.o: $(SRC)/stEmp.c
	$(CC) $(CFLAGS) $(OFLAGS) $(OBJ)/stEmp.o $(SRC)/stEmp.c $(IFLAGS) $(INC)/

$(OBJ)/stEmp2.o: $(SRC)/stEmp2.c
	$(CC) $(CFLAGS) $(OFLAGS) $(OBJ)/stEmp2.o $(SRC)/stEmp2.c $(IFLAGS) $(INC)/

$(OBJ)/getDetails.o: $(SRC)/getDetails.c
	$(CC) $(CFLAGS) $(OFLAGS) $(OBJ)/getDetails.o $(SRC)/getDetails.c $(IFLAGS) $(INC)/


clean:
	@echo "Cleaning in Progress"
	rm -rf $(BIN)/*
	rm -rf $(OBJ)/*
	@echo "Cleaning is Done!"
