#include <stdio.h>

// Definition of the THFile struct
typedef struct {
    int isBinary;
    int isAutoSpacing;
} THFile;

// Function to set isBinary flag to 1
void THFile_binary(THFile *self) {
    self->isBinary = 1;
}

// Function to set isBinary flag to 0
void THFile_ascii(THFile *self) {
    self->isBinary = 0;
}

// Function to set isAutoSpacing flag to 1
void THFile_autoSpacing(THFile *self) {
    self->isAutoSpacing = 1;
}

// Function to reset THFile to default state
void THFile_reset(THFile *self) {
    self->isBinary = 1;
    self->isAutoSpacing = 0;
}

int main() {
    // Example usage
    THFile file;
    THFile_reset(&file); // Reset to default state
    THFile_ascii(&file); // Set to ASCII mode
    THFile_autoSpacing(&file); // Enable auto spacing
    THFile_binary(&file); // Set back to binary mode
    return 0;
}
