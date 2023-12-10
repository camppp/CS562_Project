#include <windows.h>

void* secureMemoryAllocation(size_t size, void* data) {
    // Allocate memory with executable permissions
    void* securedMemory = VirtualAlloc(0, size, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
    
    if (securedMemory != NULL) {
        // Copy data into the secured memory
        memcpy(securedMemory, data, size);
    }
    
    return securedMemory;
}
