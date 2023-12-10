#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    if (argc < 2) {
        // Print an error message indicating insufficient arguments
        printf("Error: Insufficient arguments\n");
        return 1;
    }

    if (strcmp(argv[1], "add") == 0 && argc == 4) {
        int num1 = atoi(argv[2]);
        int num2 = atoi(argv[3]);
        printf("Sum: %d\n", num1 + num2);
    } else if (strcmp(argv[1], "subtract") == 0 && argc == 4) {
        int num1 = atoi(argv[2]);
        int num2 = atoi(argv[3]);
        printf("Difference: %d\n", num1 - num2);
    } else {
        printf("Error: Invalid command or insufficient arguments\n");
        return 1;
    }

    return 0;
}
