#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>

long randomWriteThenRead(int blockSize) {
    clock_t start, end;
    double cpu_time_used;

    int returnVal;
    char *b;
    int i, r;

    // Open file for writing
    returnVal = open("test.txt", O_CREAT | O_TRUNC | O_WRONLY, 0666);
    if (returnVal == -1) {
        // Handle error
        return -1;
    }

    // Perform random writes
    start = clock();
    for (i = 0; i < 1000000000 / blockSize; i++) {
        r = rand() % (1000000000 / blockSize);
        b = (char *)malloc(blockSize * sizeof(char));
        memset(b, '0', blockSize);
        write(returnVal, b, blockSize);
        free(b);
    }
    end = clock();
    close(returnVal);

    // Open file for reading
    returnVal = open("test.txt", O_RDONLY);
    if (returnVal == -1) {
        // Handle error
        return -1;
    }

    // Read the data back and discard
    start = clock();
    for (i = 0; i < 1000000000 / blockSize; i++) {
        b = (char *)malloc(blockSize * sizeof(char));
        read(returnVal, b, blockSize);
        free(b);
    }
    end = clock();
    close(returnVal);

    // Calculate and return the total time taken in milliseconds
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
    return (long)cpu_time_used;
}
