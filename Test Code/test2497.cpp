#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/mman.h>
#include <errno.h>

void* memoryMap(uint32_t mmapLen, uint32_t mmapAddr) {
    void* mappedMemory = mmap((void*)mmapAddr, mmapLen, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    if (mappedMemory == MAP_FAILED) {
        perror("mmap");
        return NULL;
    }
    return mappedMemory;
}
