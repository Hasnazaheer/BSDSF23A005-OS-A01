CC = gcc
CFLAGS = -Wall -Iinclude

SRC_UTILS = src/mystrfunctions.c src/myfilefunctions.c
OBJ_UTILS = obj/mystrfunctions.o obj/myfilefunctions.o

SRC_MAIN = src/main.c
OBJ_MAIN = obj/main.o

BIN_DIR = bin
LIB_DIR = lib
OBJ_DIR = obj

# Targets
all: client_static client_dynamic

# --- Static Library ---
lib/libmyutils.a: $(OBJ_UTILS)
	mkdir -p $(LIB_DIR) $(OBJ_DIR)
	ar rcs $@ $^

client_static: lib/libmyutils.a $(OBJ_MAIN)
	mkdir -p $(BIN_DIR)
	$(CC) $(OBJ_MAIN) -L$(LIB_DIR) -lmyutils -o $(BIN_DIR)/client_static

# --- Dynamic Library ---
lib/libmyutils.so: $(OBJ_UTILS)
	mkdir -p $(LIB_DIR) $(OBJ_DIR)
	$(CC) -fPIC -c src/mystrfunctions.c -o obj/mystrfunctions.o
	$(CC) -fPIC -c src/myfilefunctions.c -o obj/myfilefunctions.o
	$(CC) -shared -o lib/libmyutils.so obj/mystrfunctions.o obj/myfilefunctions.o

client_dynamic: lib/libmyutils.so $(OBJ_MAIN)
	mkdir -p $(BIN_DIR)
	$(CC) $(OBJ_MAIN) -L$(LIB_DIR) -lmyutils -o $(BIN_DIR)/client_dynamic

# --- Object files ---
obj/%.o: src/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# --- Clean ---
clean:
	rm -rf $(OBJ_DIR)/*.o $(BIN_DIR)/* $(LIB_DIR)/*

install: client_dynamic manpage
	sudo cp bin/client_dynamic /usr/local/bin/client
	sudo cp man/man3/client.1 /usr/local/share/man/man3/

manpage:
	@echo "Man page ready"
