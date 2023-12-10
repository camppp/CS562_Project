#include <string>

std::string FormatBinary(unsigned int n, unsigned int w) {
    std::string s;

    for (unsigned int i = 0; i < w; i++) {
        s = ((n & 1) ? '1' : '0') + s;
        n >>= 1;
    }

    return s;
}
