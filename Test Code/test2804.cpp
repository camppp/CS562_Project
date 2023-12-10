#include <iostream>
#include <vector>
#include <string>

int countSubstringOccurrences(const std::vector<std::string>& inputStrings, const std::string& substring) {
    int count = 0;
    for (const std::string& str : inputStrings) {
        size_t pos = 0;
        while ((pos = str.find(substring, pos)) != std::string::npos) {
            ++count;
            pos += substring.length();
        }
    }
    return count;
}

int main() {
    std::vector<std::string> inputStrings = {"apple", "banana", "pineapple", "grape"};
    std::string substring = "ap";
    int occurrences = countSubstringOccurrences(inputStrings, substring);
    std::cout << "Total occurrences of substring: " << occurrences << std::endl;
    return 0;
}
