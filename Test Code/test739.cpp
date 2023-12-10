#include <cstdlib>
#include <cstdint>

void* custom_aligned_alloc(size_t size, size_t align) {
    void* ptr = nullptr;
    #ifdef _WIN32
        ptr = _aligned_malloc(size, align);
    #else
        if (posix_memalign(&ptr, align, size) != 0) {
            ptr = nullptr;
        }
    #endif
    return ptr;
}

void custom_aligned_free(void* ptr) {
    #ifdef _WIN32
        _aligned_free(ptr);
    #else
        free(ptr);
    #endif
}
