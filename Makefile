# Compiler and flags
CC=clang
CFLAGS=-Wall -Wextra -std=c17 -g

# Source files (all .c in src/)
SRC=$(wildcard src/*.c)

# Object files (replace .c with .o)
OBJ=$(SRC:.c=.o)

# Output binary
OUT=stockmon

# Default target
all: $(OUT)

# Link object files to create the binary
$(OUT): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(OUT)

# Compile each .c file into .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f $(OBJ) $(OUT)
