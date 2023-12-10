#include <stdio.h>
#include <stdlib.h>

void SetLoadFilesToMemory(const char* fileNames)
{
    // Attempt to open the file
    FILE* file = fopen(fileNames, "rb");
    if (file == NULL) {
        fprintf(stderr, "Error: Unable to open file %s\n", fileNames);
        return;
    }

    // Determine the file size
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);

    // Allocate memory to store the file contents
    char* buffer = (char*)malloc(fileSize * sizeof(char));
    if (buffer == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for file %s\n", fileNames);
        fclose(file);
        return;
    }

    // Read the file contents into memory
    size_t bytesRead = fread(buffer, 1, fileSize, file);
    if (bytesRead != fileSize) {
        fprintf(stderr, "Error: Failed to read entire file %s into memory\n", fileNames);
        free(buffer);
        fclose(file);
        return;
    }

    // Perform processing on the loaded data (e.g., print the contents)
    printf("Contents of file %s:\n%s\n", fileNames, buffer);

    // Clean up resources
    free(buffer);
    fclose(file);
}
