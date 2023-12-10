c
int main(int argc, char **argv)
{
    if (argc < 2) {
        // Print an error message indicating insufficient arguments
        printf("Error: Insufficient arguments\n");
        return 1;
    }

    // Check the first argument
    if (strcmp(argv[1], "add") == 0) {
        // Add the two integers
        int a = atoi(argv[2]);
        int b = atoi(argv[3]);
        int sum = a + b;
        printf("Sum: %d\n", sum);
    } else if (strcmp(argv[1], "subtract") == 0) {
        // Subtract the two integers
        int a = atoi(argv[2]);
        int b = atoi(argv[3]);
        int diff = a - b;
        printf("Difference: %d\n", diff);
    } else {
        // Print an error message indicating an invalid command
        printf("Error: Invalid command\n");
        return 1;
    }

    return 0;
}
