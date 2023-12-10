#include <stdio.h>
#include <stdlib.h>
#include "randombytes.h"

char* generateRandomPassword(int length) {
    char* password = (char*)malloc((length + 1) * sizeof(char));  // Allocate memory for the password
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*";  // Define the character set for the password

    for (int i = 0; i < length; i++) {
        password[i] = charset[randombytes_uniform(sizeof(charset) - 1)];  // Generate random characters from the charset
    }
    password[length] = '\0';  // Null-terminate the password string

    return password;
}

int main() {
    int length = 10;
    char* password = generateRandomPassword(length);
    printf("Random Password: %s\n", password);
    free(password);  // Free the allocated memory
    return 0;
}
