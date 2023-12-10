#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int square(int num) {
    return num * num;
}

int cube(int num) {
    return num * num * num;
}

int factorial(int num) {
    if (num == 0 || num == 1) {
        return 1;
    } else {
        int result = 1;
        for (int i = 2; i <= num; i++) {
            result *= i;
        }
        return result;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <operation> <number>\n", argv[0]);
        return 1;
    }

    char *operation = argv[1];
    int number = atoi(argv[2]);

    if (strcmp(operation, "square") == 0) {
        printf("%d\n", square(number));
    } else if (strcmp(operation, "cube") == 0) {
        printf("%d\n", cube(number));
    } else if (strcmp(operation, "factorial") == 0) {
        printf("%d\n", factorial(number));
    } else {
        printf("Invalid operation: %s\n", operation);
        return 1;
    }

    return 0;
}
