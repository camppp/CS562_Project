#include <cstdint>

ULONG_PTR patternSearch(ULONG_PTR AsmHandler, ULONG_PTR AsmHandlerEnd, ULONG_PTR pattern) {
    // Calculate the size of the memory range
    SIZE_T asmHandlerSize = AsmHandlerEnd - AsmHandler;

    // Iterate over the memory range
    for (ULONG_PTR ptr = AsmHandler; ptr < AsmHandlerEnd; ptr += 8) {
        // Read 64-bit block of memory
        ULONG_PTR block = *(ULONG_PTR*)ptr;

        // Compare the block of memory with the pattern
        if (block == pattern) {
            // Return the address of the match
            return ptr;
        }
    }

    // If no match is found, return NULL
    return NULL;
}