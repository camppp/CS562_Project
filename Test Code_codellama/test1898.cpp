#include <iostream>
#include <vector>

std::vector<uint8_t> encodeVariableLength(uint32_t value) {
    std::vector<uint8_t> result;
    while (value > 0) {
        uint8_t byte = value & 0x7F;
        value >>= 7;
        if (value > 0) {
            byte |= 0x80;
        }
        result.push_back(byte);
    }
    return result;
}
