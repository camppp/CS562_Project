#include <iostream>
#include <string>
#include <cstdint>

std::string FromWideString(const std::u16string& str) {
    std::string result;
    for (auto c : str) {
        if (c < 0x80) {
            result += c;
        } else if (c < 0x800) {
            result += 0xc0 | (c >> 6);
            result += 0x80 | (c & 0x3f);
        } else if (c < 0x10000) {
            result += 0xe0 | (c >> 12);
            result += 0x80 | ((c >> 6) & 0x3f);
            result += 0x80 | (c & 0x3f);
        } else {
            result += 0xf0 | (c >> 18);
            result += 0x80 | ((c >> 12) & 0x3f);
            result += 0x80 | ((c >> 6) & 0x3f);
            result += 0x80 | (c & 0x3f);
        }
    }
    return result;
}

std::u16string ToWideString(const std::string& str) {
    std::u16string result;
    for (auto c : str) {
        if (c < 0x80) {
            result += c;
        } else if (c < 0xc2) {
            result += 0xfffd;
        } else if (c < 0xe0) {
            result += (c & 0x1f) << 6;
        } else if (c < 0xf0) {
            result += (c & 0x0f) << 12;
        } else if (c < 0xf8) {
            result += (c & 0x07) << 18;
        } else {
            result += 0xfffd;
        }
    }
    return result;
}

int main() {
    std::u16string str = u"hello";
    std::string utf8 = FromWideString(str);
    std::cout << "UTF-8: " << utf8 << std::endl;

    std::string str2 = "world";
    std::u16string utf16 = ToWideString(str2);
    std::cout << "UTF-16: " << utf16 << std::endl;

    return 0;
}
