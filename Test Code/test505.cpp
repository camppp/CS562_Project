c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <randombytes.h>

#define PASSWORD_LENGTH 10

char* generateRandomPassword(int length) {
    char* password = (char*)malloc(length + 1);
    if (password == NULL) {
        fprintf(stderr, "Error: unable to allocate memory for password\n");
        return NULL;
    }

    for (int i = 0; i < length; i++) {
        password[i] = (char)randombytes_buf(1);
        if (password[i] < 0x30 || password[i] > 0x39) {
            password[i] += 0x30;
        } else if (password[i] < 0x41 || password[i] > 0x5A) {
            password[i] += 0x41;
        } else if (password[i] < 0x61 || password[i] > 0x7A) {
            password[i] += 0x61;
        } else {
            password[i] += 0x21;
        }
    }

    password[length] = '\0';
    return password;
}

int main() {
    char* password = generateRandomPassword(PASSWORD_LENGTH);
    printf("Generated password: %s\n", password);
    free(password);
    return 0;
}
