#include <stdio.h>
#include <stdlib.h>
#include "../include/mystrfunctions.h"
#include "../include/myfilefunctions.h"

int main() {
    printf("--- Testing String Functions ---\n");

    char str1[50] = "Hello";
    char str2[50] = "World";
    char buffer[50];

    printf("Length of str1: %d\n", mystrlen(str1));

    mystrcpy(buffer, str1);
    printf("Copied str1 into buffer: %s\n", buffer);

    mystrncpy(buffer, str2, 3);
    printf("Copied first 3 chars of str2 into buffer: %s\n", buffer);

    mystrcat(str1, str2);
    printf("Concatenated str1 and str2: %s\n", str1);

    printf("\n--- Testing File Functions ---\n");

    FILE* fp = fopen("test.txt", "r");
    if (!fp) {
        printf("Could not open test.txt. Please create it first.\n");
        return 1;
    }

    int lines, words, chars;
    if (wordCount(fp, &lines, &words, &chars) == 0) {
        printf("Lines: %d, Words: %d, Chars: %d\n", lines, words, chars);
    } else {
        printf("Error reading file for wordCount.\n");
    }

    char** matches = NULL;
    int count = mygrep(fp, "hello", &matches);
    if (count >= 0) {
        printf("Found %d matching lines containing 'hello':\n", count);
        for (int i = 0; i < count; i++) {
            printf("%s", matches[i]);
            free(matches[i]);
        }
        free(matches);
    } else {
        printf("Error running mygrep.\n");
    }

    fclose(fp);

    return 0;
}
