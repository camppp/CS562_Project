#include <stdlib.h>
#include <stdint.h>

#define ALIGNMENT 16

void* custom_aligned_alloc(size_t size, size_t align) {
    void* ptr = NULL;
    if (align < ALIGNMENT) {
        align = ALIGNMENT;
    }
    ptr = aligned_alloc(size, align);
    if (ptr == NULL) {
        return NULL;
    }
    return ptr;
}

void custom_aligned_free(void* ptr) {
    aligned_free(ptr);
}
