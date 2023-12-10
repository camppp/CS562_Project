#include <iostream>
#include <cctype>

namespace XPlatform {
    namespace Syscall {
        int StringCompareIgnoreCase(const std::string& str1, const std::string& str2) {
            size_t len1 = str1.length();
            size_t len2 = str2.length();
            size_t minLen = (len1 < len2) ? len1 : len2;

            for (size_t i = 0; i < minLen; ++i) {
                char c1 = std::tolower(str1[i]);
                char c2 = std::tolower(str2[i]);
                if (c1 != c2) {
                    return (c1 < c2) ? -1 : 1;
                }
            }

            if (len1 == len2) {
                return 0;
            } else {
                return (len1 < len2) ? -1 : 1;
            }
        }
    }
}

int main() {
    std::cout << XPlatform::Syscall::StringCompareIgnoreCase("aBcDeF", "AbCdEf") << std::endl;
    std::cout << XPlatform::Syscall::StringCompareIgnoreCase("", "") << std::endl;
    std::cout << XPlatform::Syscall::StringCompareIgnoreCase("12345", "abcde") << std::endl;
    return 0;
}
