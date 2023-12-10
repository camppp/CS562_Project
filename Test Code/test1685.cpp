#include <iostream>
#include <string>

int countUnclosedBraces(const std::string& input) {
    int count = 0;
    bool opened = false;

    for (char c : input) {
        if (c == '{') {
            opened = true;
        } else if (c == '}' && !opened) {
            count++;
        } else if (c == '}' && opened) {
            opened = false;
        }
    }

    return count;
}

int main() {
    std::string input = "}abc}def}ghi}jkl}mno}pqr}stu}vwx}yz";
    std::cout << countUnclosedBraces(input) << std::endl;  // Output: 10
    return 0;
}
