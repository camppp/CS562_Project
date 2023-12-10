#include <stdio.h>

FILE* openFileForWriting(const char* azFileName) {
    FILE* mpFile;
    errno_t err = fopen_s(&mpFile, azFileName, "wb");
    if (err == 0) {
        return mpFile;  // File opened successfully, return the file stream
    } else {
        // File opening failed, handle the error
        switch (err) {
            case EINVAL:
                printf("Invalid parameter passed to fopen_s\n");
                break;
            case EACCES:
                printf("Permission denied or file is in use by another process\n");
                break;
            case ENOENT:
                printf("File or path not found\n");
                break;
            default:
                printf("Error opening file: %d\n", err);
                break;
        }
        return NULL;  // Return NULL to indicate failure
    }
}
