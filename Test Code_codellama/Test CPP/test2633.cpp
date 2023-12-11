c
#include <stdio.h>
#include <stdlib.h>

char* readFileIntoBuffer(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return NULL; // Return NULL if file cannot be opened
    }

    // Determine the size of the file
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    // Allocate memory for the buffer
    char* buffer = (char*)malloc(file_size * sizeof(char));

    // Read file contents into the buffer
    for (long i = 0; i < file_size; i++) {
        buffer[i] = fgetc(file);
    }

    fclose(file);
    return buffer;
}
