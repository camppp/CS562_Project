#include <stdio.h>
#include <stdlib.h>

char* intToString(int num) {
    int temp = num;
    int count = 0;
    while (temp != 0) {
        temp /= 10;
        count++;
    }

    char* result = (char*)malloc((count + 1) * sizeof(char));
    if (result == NULL) {
        return NULL; // Memory allocation failed
    }

    if (num == 0) {
        result[0] = '0';
        result[1] = '\0';
        return result;
    }

    int i = count - 1;
    while (num != 0) {
        int digit = num % 10;
        result[i] = digit + '0';
        num /= 10;
        i--;
    }
    result[count] = '\0';

    return result;
}
