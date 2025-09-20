# Compiler we will use
CC = gcc

# Compiler options: show warnings, look for headers in "include" folder
CFLAGS = -Wall -Iinclude

# Final program name
TARGET = bin/client

# Object files (compiled versions of .c files)
OBJ = obj/main.o obj/mystrfunctions.o obj/myfilefunctions.o

# --- Rule 1: Build the final program ---
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

# --- Rule 2: How to make .o files from .c files ---
obj/%.o: src/%.c
	@mkdir -p obj bin       # make sure folders exist
	$(CC) $(CFLAGS) -c $< -o $@

# --- Rule 3: Clean up ---
clean:
	rm -rf obj/*.o $(TARGET)
