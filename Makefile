CC = gcc
CFLAGS = -Wall -Iinclude

SRC = src/main.c
OBJ = obj/main.o

LIB_NAME = libmyutils.a
LIB_DIR = lib
LIB = $(LIB_DIR)/$(LIB_NAME)

TARGET = bin/client_static

# Default target
all: $(TARGET)

# Rule for final executable linking against the static library
$(TARGET): $(OBJ) $(LIB)
	$(CC) $(CFLAGS) -o $@ $(OBJ) -L$(LIB_DIR) -lmyutils

# Rule for static library
$(LIB): obj/mystrfunctions.o obj/myfilefunctions.o
	ar rcs $@ $^

# Compile source to object
obj/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf obj/*.o bin/* lib/*.a

