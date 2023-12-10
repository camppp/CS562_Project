#include <stdio.h>

int64_t SeekFile(int file, int64_t offset)
{
    // Seek to the specified offset in the file
    fseek(file, offset, SEEK_SET);

    // Obtain the new position after seeking
    int64_t newPosition = ftell(file);

    return newPosition;
}
