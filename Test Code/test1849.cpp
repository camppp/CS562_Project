#include <cstdint>
#include <cstring>
#include <algorithm>

void manipulateData(uint8_t* buf, int startBit, int length, uint64_t mask, uint64_t valAsBits) {
    uint64_t data = 0;

    // Reverse the order of bytes in the buffer
    std::reverse(buf, buf + 8);

    // Extract a 64-bit integer from the reversed buffer
    std::memcpy(&data, buf, sizeof(data));

    // Apply bitwise operations to modify the extracted data
    data &= ~(mask << (64 - startBit - length));
    data |= valAsBits << (64 - startBit - length);

    // Store the modified data back in the buffer
    std::memcpy(buf, &data, sizeof(data);

    // Reverse the order of bytes in the modified buffer
    std::reverse(buf, buf + 8);
}
