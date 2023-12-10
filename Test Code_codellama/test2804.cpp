#include <iostream>
#include <vector>
#include <string>

int countSubstringOccurrences(const std::vector<std::string>& inputStrings, const std::string& substring) {
    int count = 0;
    for (const auto& str : inputStrings) {
        size_t pos = 0;
        while ((pos = str.find(substring, pos)) != std::string::npos) {
            ++count;
            ++pos;
        }
    }
    return count;
}

int main() {
    std::vector<std::string> inputStrings = {"apple", "banana", "pineapple", "grape"};
    std::string substring = "ap";
    int count = countSubstringOccurrences(inputStrings, substring);
    std::cout << "The substring \"" << substring << "\" appears " << count << " times in the input strings." << std::endl;
    return 0;
}
