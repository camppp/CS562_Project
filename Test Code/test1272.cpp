#include <iostream>

bool IsRunningOnWow64() {
    // Assume implementation of IsRunningOnWow64() function
    return dwCachedWow64; // Placeholder for the actual implementation
}

inline size_t ALIGNUP(size_t nSize) {
    if (IsRunningOnWow64()) {
        // If running on a 64-bit system, use 64-bit alignment
        return ((nSize + (sizeof(DWORD64) - 1)) & ~(sizeof(DWORD64) - 1));
    } else {
        // If running on a 32-bit system, use 32-bit alignment
        return ((nSize + (sizeof(DWORD) - 1)) & ~(sizeof(DWORD) - 1));
    }
}

int main() {
    // Test the ALIGNUP function
    size_t size1 = 20;
    size_t alignedSize1 = ALIGNUP(size1);
    std::cout << "Aligned size for " << size1 << " is " << alignedSize1 << std::endl;

    size_t size2 = 100;
    size_t alignedSize2 = ALIGNUP(size2);
    std::cout << "Aligned size for " << size2 << " is " << alignedSize2 << std::endl;

    return 0;
}
