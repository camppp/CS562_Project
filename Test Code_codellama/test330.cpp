c
#include <stdio.h>
#include <stdlib.h>

int handleLibraryLoadingError(const char* libraryName, const char* errorMessage) {
    printf("Failed to open %s (%s)\n", libraryName, errorMessage);
    return -1;
}
