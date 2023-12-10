#include <string>

bool isValidUTF8(const std::string& input) {
    for (size_t i = 0; i < input.size(); i++) {
        if (input[i] & 0x80) {  // Check if the byte has the leading 1 bit set
            if (i + 1 >= input.size()) {  // Check if there are enough bytes left in the string
                return false;
            }
            if ((input[i] & 0xE0) == 0xC0 && (input[i + 1] & 0xC0) == 0x80) {  // Check if the byte is a continuation byte
                i++;  // Skip the continuation byte
            } else {
                return false;
            }
        }
    }
    return true;
}
