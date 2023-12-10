c
int dirbuf_add(dirent **buf, size_t *remain, ino_t ino, off_t off, unsigned char type, const char *name) {
    // Calculate the size of the directory entry
    size_t entry_size = sizeof(dirent) + strlen(name) + 1;

    // Check if the buffer is large enough to hold the new entry
    if (*remain < entry_size) {
        // Reallocate the buffer to double its size
        *buf = realloc(*buf, (*remain) * 2);
        if (*buf == NULL) {
            return -1;
        }
        *remain = (*remain) * 2;
    }

    // Add the directory entry to the buffer
    dirent *entry = (dirent *)(*buf + *remain - entry_size);
    entry->ino = ino;
    entry->off = off;
    entry->type = type;
    strcpy(entry->name, name);

    // Update the remaining size of the buffer
    *remain -= entry_size;

    return 0;
}
