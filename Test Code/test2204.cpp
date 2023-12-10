#include <iostream>
#include <string>

namespace String {
    std::string concat(const std::string& str1, const std::string& str2) {
        return str1 + str2;
    }

    std::string substring(const std::string& str, int start, int end) {
        if (start < 0) start = 0;
        if (end > str.length()) end = str.length();
        if (start > end) return "";
        return str.substr(start, end - start);
    }

    std::string replace(const std::string& str, char to_replace, char replacement) {
        std::string result = str;
        for (char& c : result) {
            if (c == to_replace) {
                c = replacement;
            }
        }
        return result;
    }
}

int main() {
    std::string str1 = "Hello, ";
    std::string str2 = "world!";
    std::cout << String::concat(str1, str2) << std::endl;  // Output: Hello, world!
    std::cout << String::substring(str1, 0, 5) << std::endl;  // Output: Hello
    std::cout << String::replace(str1, 'l', 'L') << std::endl;  // Output: HeLLo, 
    return 0;
}
