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
    char* buffer = (char*)malloc((file_size + 1) * sizeof(char)); // Allocate an extra byte for null-terminator

    // Read file contents into the buffer
    if (fread(buffer, 1, file_size, file) != file_size) {
        fclose(file);
        free(buffer);
        return NULL; // Return NULL if reading file contents fails
    }

    buffer[file_size] = '\0'; // Null-terminate the buffer

    fclose(file);
    return buffer;
}

int main() {
    const char* filename = "example.txt";
    char* buffer = readFileIntoBuffer(filename);
    if (buffer != NULL) {
        printf("File contents: %s\n", buffer);
        free(buffer); // Free the allocated memory
    } else {
        printf("Failed to open the file.\n");
    }
    return 0;
}
