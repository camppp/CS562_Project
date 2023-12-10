#include <string>

bool isValidUTF8(const std::string& input) {
    int remainingBytes = 0;
    for (char c : input) {
        if (remainingBytes == 0) {
            if ((c & 0b10000000) == 0) {
                continue;  // Single byte character
            } else if ((c & 0b11100000) == 0b11000000) {
                remainingBytes = 1;  // Two byte character
            } else if ((c & 0b11110000) == 0b11100000) {
                remainingBytes = 2;  // Three byte character
            } else if ((c & 0b11111000) == 0b11110000) {
                remainingBytes = 3;  // Four byte character
            } else {
                return false;  // Invalid leading byte
            }
        } else {
            if ((c & 0b11000000) != 0b10000000) {
                return false;  // Invalid subsequent byte
            }
            remainingBytes--;
        }
    }
    return remainingBytes == 0;  // All multi-byte characters have been completed
}
