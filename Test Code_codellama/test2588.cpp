c
int64_t SeekFile(int file, int64_t offset)
{
    // Check if the file is valid
    if (file < 0) {
        return -1;
    }

    // Check if the offset is valid
    if (offset < 0) {
        return -1;
    }

    // Seek to the specified offset
    int64_t new_position = lseek(file, offset, SEEK_SET);

    // Check if the seek was successful
    if (new_position == -1) {
        return -1;
    }

    // Return the new position after seeking
    return new_position;
}
