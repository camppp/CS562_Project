#include <iostream>
#include <string>
#include <unordered_map>

std::string base64Encode(const std::string &input) {
    const std::string base64Chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    std::string encoded;
    int val = 0;
    int bits = -6;
    const unsigned int mask = 0x3F; // 6 bits

    for (const char &ch : input) {
        val = (val << 8) + ch;
        bits += 8;
        while (bits >= 0) {
            encoded.push_back(base64Chars[(val >> bits) & mask]);
            bits -= 6;
        }
    }

    if (bits > -6) {
        encoded.push_back(base64Chars[((val << 8) >> (bits + 8)) & mask]);
    }

    while (encoded.size() % 4 != 0) {
        encoded.push_back('=');
    }

    return encoded;
}

std::string base64Decode(const std::string &input) {
    const std::string base64Chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    std::unordered_map<char, int> base64Map;
    for (int i = 0; i < 64; ++i) {
        base64Map[base64Chars[i]] = i;
    }

    std::string decoded;
    int val = 0;
    int bits = -8;

    for (const char &ch : input) {
        if (ch == '=') {
            break;
        }
        val = (val << 6) + base64Map[ch];
        bits += 6;
        if (bits >= 0) {
            decoded.push_back((val >> bits) & 0xFF);
            bits -= 8;
        }
    }

    return decoded;
}

int main() {
    std::string original = "Hello, World!";
    std::string encoded = base64Encode(original);
    std::string decoded = base64Decode(encoded);

    std::cout << "Original: " << original << std::endl;
    std::cout << "Encoded: " << encoded << std::endl;
    std::cout << "Decoded: " << decoded << std::endl;

    return 0;
}
