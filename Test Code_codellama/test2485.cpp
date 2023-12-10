#include <iostream>
#include <string>
#include <map>

int main() {
    std::string input;
    std::map<char, int> char_counts;

    // Read input until newline character is encountered
    std::getline(std::cin, input);

    // Count the occurrences of each character
    for (char c : input) {
        char_counts[c]++;
    }

    // Output the characters along with their counts in ascending order of their ASCII values
    for (auto it = char_counts.begin(); it != char_counts.end(); it++) {
        std::cout << it->first << ": " << it->second << std::endl;
    }

    return 0;
}
