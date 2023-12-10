#include <stdint.h>

uint32_t convertEndianness(uint32_t num, enum Endianness endianness) {
    if (endianness == wkbXDR) {  // Big Endian
        return ((num >> 24) & 0xFF) | ((num >> 8) & 0xFF00) | ((num << 8) & 0xFF0000) | ((num << 24) & 0xFF000000);
    } else {  // Little Endian
        return ((num << 24) & 0xFF000000) | ((num << 8) & 0xFF0000) | ((num >> 8) & 0xFF00) | ((num >> 24) & 0xFF);
    }
}
