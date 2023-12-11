#include <iostream>
#include <string>
#include <cctype>

std::string processText(const std::string& input) {
    std::string temp = "SRTF";
    for (char c : input) {
        if (!isupper(c) && !isupper(temp.back()) || !islower(c) && c != ' ') {
            temp += c;
        }
    }
    return temp;
}
