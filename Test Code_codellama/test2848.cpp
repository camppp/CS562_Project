#include <string>
#include <algorithm>

enum class CaseSensitivity { SENSITIVE, INSENSITIVE };

bool compareStrings(const std::string& str1, const std::string& str2, CaseSensitivity sensitivity) {
    if (sensitivity == CaseSensitivity::SENSITIVE) {
        return str1 == str2;
    } else {
        return std::equal(str1.begin(), str1.end(), str2.begin(), str2.end(),
                          [](char c1, char c2) { return std::tolower(c1) == std::tolower(c2); });
    }
}
