#include <string>

class HashId {
public:
    static const char kHexConversion[];
};

const char HashId::kHexConversion[] = "0123456789abcdef";

std::string DecimalToHex(int decimal) {
    if (decimal == 0) {
        return "0";
    }

    std::string hex;
    while (decimal > 0) {
        int remainder = decimal % 16;
        hex = HashId::kHexConversion[remainder] + hex;
        decimal /= 16;
    }

    return hex;
}
