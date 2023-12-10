#include <cstdlib>

struct Struct {
    int data1;
    char data2;
    double data3;
};

void* customAllocate(size_t size) {
    return malloc(size);
}

void customDeallocate(void* ptr) {
    free(ptr);
}
