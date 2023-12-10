c
#include <vector>
#include <cstdio>

std::vector<off_t> find_non_zero_bytes(int fd, off_t start, off_t end) {
    std::vector<off_t> nonZeroPositions;

    // Check if the file descriptor is valid
    if (fd < 0) {
        return nonZeroPositions;
    }

    // Check if the start and end positions are valid
    if (start < 0 || end < 0 || start > end) {
        return nonZeroPositions;
    }

    // Read the file descriptor from the start position to the end position
    char buffer[1024];
    off_t currentPosition = start;
    while (currentPosition < end) {
        // Read up to 1024 bytes from the file descriptor
        ssize_t bytesRead = pread(fd, buffer, 1024, currentPosition);
        if (bytesRead < 0) {
            // Read operation failed
            return nonZeroPositions;
        }

        // Check for non-zero bytes in the buffer
        for (int i = 0; i < bytesRead; i++) {
            if (buffer[i] != 0) {
                nonZeroPositions.push_back(currentPosition + i);
            }
        }

        // Update the current position
        currentPosition += bytesRead;
    }

    return nonZeroPositions;
}
