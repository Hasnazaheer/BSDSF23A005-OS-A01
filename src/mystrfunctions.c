#include "../include/mystrfunctions.h"

int mystrlen(const char* s) {
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

int mystrcpy(char* dest, const char* src) {
    int i = 0;
    while ((dest[i] = src[i]) != '\0') {
        i++;
    }
    return i; // number of chars copied
}

int mystrncpy(char* dest, const char* src, int n) {
    int i = 0;
    while (i < n && src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return i; // number of chars copied
}

int mystrcat(char* dest, const char* src) {
    int i = 0, j = 0;
    while (dest[i] != '\0') {
        i++;
    }
    while ((dest[i++] = src[j++]) != '\0');
    return i - 1; // new length of dest
}
