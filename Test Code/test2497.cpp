c
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>

void* memoryMap(uint32_t mmapLen, uint32_t mmapAddr) {
    void* mappedMemory = NULL;
    int fd = open("/dev/zero", O_RDWR);
    if (fd == -1) {
        perror("open");
        return NULL;
    }

    mappedMemory = mmap(NULL, mmapLen, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);
    if (mappedMemory == MAP_FAILED) {
        perror("mmap");
        close(fd);
        return NULL;
    }

    close(fd);
    return mappedMemory;
}
