#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/myfilefunctions.h"

// Count lines, words, characters
int wordCount(FILE* file, int* lines, int* words, int* chars) {
    if (!file) return -1;

    *lines = *words = *chars = 0;
    char ch, prev = ' ';

    while ((ch = fgetc(file)) != EOF) {
        (*chars)++;
        if (ch == '\n') (*lines)++;
        if ((ch == ' ' || ch == '\n' || ch == '\t') && prev != ' ' && prev != '\n' && prev != '\t') {
            (*words)++;
        }
        prev = ch;
    }

    if (prev != ' ' && prev != '\n' && prev != '\t') {
        (*words)++;
    }

    rewind(file); // reset pointer for reuse
    return 0;
}

// Search for lines containing search_str
int mygrep(FILE* fp, const char* search_str, char*** matches) {
    if (!fp || !search_str) return -1;

    size_t capacity = 10;
    size_t count = 0;
    *matches = malloc(capacity * sizeof(char*));

    if (!*matches) return -1;

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), fp)) {
        if (strstr(buffer, search_str)) {
            if (count == capacity) {
                capacity *= 2;
                *matches = realloc(*matches, capacity * sizeof(char*));
                if (!*matches) return -1;
            }
            (*matches)[count] = strdup(buffer);
            count++;
        }
    }

    rewind(fp); // reset pointer
    return (int)count;
}
