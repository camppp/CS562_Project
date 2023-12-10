#include <cstddef>
#include <cstring>
#include <dirent.h>
#include <cstdlib>

int dirbuf_add(dirent **buf, size_t *remain, ino_t ino, off_t off, unsigned char type, const char *name) {
    const size_t align = alignof(dirent);
    const size_t dirent_noname = offsetof(dirent, d_name);
    size_t entry_size = dirent_noname + strlen(name) + 1; // Calculate the size of the directory entry including the name and null terminator

    // Check if the buffer needs to be reallocated
    if (*remain < entry_size) {
        size_t new_size = *remain * 2; // Double the size of the buffer
        dirent *new_buf = (dirent *)realloc(*buf, new_size);
        if (new_buf == nullptr) {
            return -1; // Memory reallocation failed
        }
        *buf = new_buf;
        *remain = new_size;
    }

    // Add the directory entry to the buffer
    dirent *entry = (dirent *)((char *)*buf + *remain - entry_size); // Calculate the position to add the new entry
    entry->d_ino = ino;
    entry->d_off = off;
    entry->d_type = type;
    strcpy(entry->d_name, name);

    *remain -= entry_size; // Update the remaining size of the buffer
    return 0; // Success
}
