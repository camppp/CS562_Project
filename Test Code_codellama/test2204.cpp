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
