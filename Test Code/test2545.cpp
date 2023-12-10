#include <stdio.h>

#define DEBUG_MSG(format, ...) \
    printf("[%s:%d] " format "\n", __FILE__, __LINE__, __VA_ARGS__)

int main() {
    DEBUG_MSG("Hello, world!");
    return 0;
}
