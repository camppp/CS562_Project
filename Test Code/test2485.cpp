#include <iostream>
#include <map>

int main() {
    std::map<char, int> charCount;
    char c;

    while ((c = getchar()) != '\n') {
        if (c >= 32 && c <= 126) {
            charCount[c]++;
        }
    }

    for (auto it = charCount.begin(); it != charCount.end(); ++it) {
        std::cout << it->first << ": " << it->second << std::endl;
    }

    return 0;
}
