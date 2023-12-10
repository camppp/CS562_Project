#include <iostream>
#include <string>
#include <cctype>

enum class CaseSensitivity : std::uint8_t {
    SENSITIVE,
    INSENSITIVE
};

bool compareStrings(const std::string& str1, const std::string& str2, CaseSensitivity sensitivity) {
    if (sensitivity == CaseSensitivity::SENSITIVE) {
        return str1 == str2;
    } else {
        if (str1.length() != str2.length()) {
            return false;
        }
        for (size_t i = 0; i < str1.length(); ++i) {
            if (std::tolower(str1[i]) != std::tolower(str2[i])) {
                return false;
            }
        }
        return true;
    }
}

int main() {
    std::string s1 = "Hello";
    std::string s2 = "hello";
    std::string s3 = "World";
    
    std::cout << std::boolalpha;
    std::cout << "Case-sensitive comparison: " << compareStrings(s1, s2, CaseSensitivity::SENSITIVE) << std::endl; // Output: false
    std::cout << "Case-insensitive comparison: " << compareStrings(s1, s2, CaseSensitivity::INSENSITIVE) << std::endl; // Output: true
    std::cout << "Case-sensitive comparison: " << compareStrings(s1, s3, CaseSensitivity::SENSITIVE) << std::endl; // Output: false
    std::cout << "Case-insensitive comparison: " << compareStrings(s1, s3, CaseSensitivity::INSENSITIVE) << std::endl; // Output: false
    return 0;
}
