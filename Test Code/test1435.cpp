#include <vector>
#include <unistd.h>
#include <fcntl.h>

std::vector<off_t> find_non_zero_bytes(int fd, off_t start, off_t end) {
    std::vector<off_t> nonZeroPositions;
    while (start < end) {
        char buffer[4096];
        size_t length = std::min((size_t)(end - start), sizeof(buffer));

        if (pread(fd, buffer, length, start) != (ssize_t)length) {
            perror("reading failed");
            return nonZeroPositions; // Return empty vector on read failure
        }

        for (size_t i = 0; i < length; i++) {
            if (buffer[i] != 0) {
                nonZeroPositions.push_back(start + i);
            }
        }
        start += length;
    }
    return nonZeroPositions;
}
