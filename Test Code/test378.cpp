#include <cstdlib>

struct Struct {
    int data1;
    char data2;
    double data3;
};

static_assert(sizeof(Struct) == 24, "Struct size is not 24 bytes");

void* customAllocate(size_t size) {
    if (size != sizeof(Struct)) {
        return nullptr;
    }
    return malloc(size);
}

void customDeallocate(void* ptr) {
    free(ptr);
}
