# Detect OS
ifeq ($(OS), Windows_NT)
    RM = del /q
    MKDIR = if not exist
    RMDIR = rmdir /s /q
    CLEAN_CMD = cmd /c "if exist $(OUTPUT_DIR) rmdir /s /q $(OUTPUT_DIR)"
    SHELL := cmd.exe
else
    RM = rm -f
    MKDIR = mkdir -p
    RMDIR = rm -rf
    CLEAN_CMD = rm -rf $(OUTPUT_DIR)
    SHELL := /bin/sh
endif

# Compiler to use
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c11

# Source and output directories
SRC_DIR = src
BIN_DIR = bin
OUTPUT_DIR = output

# Output file
OUTPUT = graphtotxt.exe

# Source files
SOURCES = $(SRC_DIR)/main.c $(SRC_DIR)/read.c $(SRC_DIR)/output.c

# Object files (stored in bin directory)
OBJECTS = $(BIN_DIR)/main.o $(BIN_DIR)/read.o $(BIN_DIR)/output.o

# Default target
all: $(OUTPUT)

# Rule to create the executable
$(OUTPUT): $(OBJECTS)
	@if not exist $(BIN_DIR) mkdir $(BIN_DIR)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(OUTPUT)

# Rule to compile source files into object files in bin directory
$(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	@if not exist $(BIN_DIR) mkdir $(BIN_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up generated files
clean:
	@if exist $(OUTPUT) del /q $(OUTPUT)
	@if exist $(BIN_DIR) del /q "$(BIN_DIR)\\*.o"
	@if exist $(OUTPUT_DIR) del /q "$(OUTPUT_DIR)\\*.txt"
