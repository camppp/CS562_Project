#include <string>

std::string convertWindows1252ToUTF8(const std::string& input) {
    std::string output;
    for (char c : input) {
        if (static_cast<unsigned char>(c) < 0x80) {
            output += c;  // ASCII characters remain the same in both encodings
        } else {
            static const char* table[] = {
                "\xe2\x82\xac",  // Euro sign
                "\xc5\xa1",      // Latin small letter s with caron
                "\xc5\xa3",      // Latin small letter t with cedilla
                "\xc5\xbe",      // Latin small letter z with caron
                "\xc5\xa0",      // Latin capital letter s with caron
                "\xc5\xbd",      // Latin capital letter z with caron
                "\xc5\xa2",      // Latin capital letter t with cedilla
                "\xc4\x90",      // Latin capital letter d with stroke
                "\xc4\x8c",      // Latin capital letter c with caron
                "\xc4\x86",      // Latin capital letter c with acute
                "\xc4\x8e",      // Latin capital letter d with caron
                "\xc4\x9e",      // Latin capital letter g with breve
                "\xc4\x9c",      // Latin capital letter g with circumflex
                "\xc5\xa4",      // Latin capital letter t with cedilla
                "\xc5\xa6",      // Latin capital letter t with stroke
                "\xc5\x9e",      // Latin capital letter s with cedilla
                "\xc5\x9a",      // Latin capital letter s with acute
                "\xc5\x9c",      // Latin capital letter s with circumflex
                "\xc5\x9e",      // Latin capital letter s with cedilla
                "\xc5\x9a",      // Latin capital letter s with acute
                "\xc5\x9c",      // Latin capital letter s with circumflex
                "\xc5\x9d",      // Latin capital letter z with acute
                "\xc5\xbb",      // Latin capital letter z with dot above
                "\xc5\xb8"       // Latin capital letter y with diaeresis
            };

            const char* conv = table[static_cast<unsigned char>(c) - 0x80];
            output += conv;
        }
    }
    return output;
}
