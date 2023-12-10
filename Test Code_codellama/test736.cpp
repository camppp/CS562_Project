c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void SetLoadFilesToMemory(const char* fileNames)
{
    // Check if the fileNames argument is null
    if (fileNames == NULL)
    {
        printf("Error: fileNames argument is null\n");
        return;
    }

    // Get the number of files to load
    int numFiles = 0;
    while (fileNames[numFiles] != '\0')
    {
        numFiles++;
    }

    // Allocate memory for the file contents
    char** fileContents = (char**)malloc(numFiles * sizeof(char*));
    if (fileContents == NULL)
    {
        printf("Error: failed to allocate memory for file contents\n");
        return;
    }

    // Load the file contents
    for (int i = 0; i < numFiles; i++)
    {
        // Open the file
        FILE* file = fopen(fileNames[i], "r");
        if (file == NULL)
        {
            printf("Error: failed to open file %s\n", fileNames[i]);
            return;
        }

        // Read the file contents
        fseek(file, 0, SEEK_END);
        long fileSize = ftell(file);
        rewind(file);
        fileContents[i] = (char*)malloc(fileSize + 1);
        if (fileContents[i] == NULL)
        {
            printf("Error: failed to allocate memory for file contents\n");
            return;
        }
        fread(fileContents[i], 1, fileSize, file);
        fclose(file);
    }

    // Perform any necessary processing on the loaded data
    // ...

    // Free the memory allocated for the file contents
    for (int i = 0; i < numFiles; i++)
    {
        free(fileContents[i]);
    }
    free(fileContents);
}
