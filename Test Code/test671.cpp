#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* modifyHTTPDate(const char* httpdate) {
    char* modifiedDate = (char*)malloc(strlen(httpdate) * 2); // Allocate memory for the modified string
    const char* ptr1 = httpdate;
    char* ptr2 = modifiedDate;

    do {
        if (*ptr1 == ' ') {
            *ptr2++ = ';'; // Replace space with semicolon
        } else {
            *ptr2++ = *ptr1; // Copy the character as is
        }
    } while (*ptr1++ != '\0');

    *ptr2 = '\0'; // Add null terminator to the modified string
    return modifiedDate;
}

int main() {
    const char* httpdate = "Sun, 06 Nov 1994 08:49:37 GMT";
    char* modifiedDate = modifyHTTPDate(httpdate);
    printf("Modified HTTP Date: %s\n", modifiedDate);
    free(modifiedDate); // Free the allocated memory
    return 0;
}
