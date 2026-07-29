# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -Iinclude

# Directories
SRC_DIR = src
TEST_DIR = test
INC_DIR = include
BUILD_DIR = build

# Source and Object files
SRCS = $(wildcard $(SRC_DIR)/*.c) $(TEST_DIR)/main.c
OBJS = $(patsubst %.c, $(BUILD_DIR)/%.o, $(notdir $(SRCS)))

# Executable name
EXEC = dslib_test

# Default target
all: $(BUILD_DIR) $(EXEC)

# Create build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Link the executable
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Compile source files to object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Compile the test/main.c file
$(BUILD_DIR)/main.o: $(TEST_DIR)/main.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target
clean:
	rm -rf $(BUILD_DIR) $(EXEC)

# Run valgrind to check for memory leaks
valgrind: $(EXEC)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(EXEC)

.PHONY: all clean valgrind