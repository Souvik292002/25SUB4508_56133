# 1. Compiler and Flags
CC      := gcc
CFLAGS  := -g -Wall -Wextra
LDFLAGS := 

# 2. Directories
SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin

# 3. File Discovery
# Finds all .c files: src/p1.c, src/p2.c, etc.
SRCS      := $(wildcard $(SRC_DIR)/*.c)

# Create a list of binaries: bin/p1, bin/p2, etc.
# $(notdir) removes the "src/" part, $(basename) removes the ".c"
BINS      := $(patsubst $(SRC_DIR)/%.c, $(BIN_DIR)/%, $(SRCS))

# 4. Default Rule: Build all binaries
all: $(BINS)

# 5. Rule to link each binary separately
# The % acts as a wildcard for the filename
$(BIN_DIR)/%: $(OBJ_DIR)/%.o | $(BIN_DIR)
	$(CC) $< -o $@ $(LDFLAGS)
	@echo "Created binary: $@"

# 6. Rule to compile each source file into an object file
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled: $<"

# 7. Directory creation
$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

# 8. Clean up
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
	@echo "Cleaned all binaries and objects."

.PHONY: all clean