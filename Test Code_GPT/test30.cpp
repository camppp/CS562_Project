#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// Function to check if a string contains a substring (case-insensitive)
bool containsSubstring(const std::string& str, const std::string& substring) {
    auto it = std::search(
        str.begin(), str.end(),
        substring.begin(), substring.end(),
        [](char ch1, char ch2) { return std::toupper(ch1) == std::toupper(ch2); }
    );

    return it != str.end();
}

// Function to count strings containing the specified substring
int countSubstringMatches(const std::vector<std::string>& candidates, const std::string& substring) {
    return std::count_if(candidates.begin(), candidates.end(),
                         [&substring](const std::string& str) {
                             return containsSubstring(str, substring);
                         });
}

int main() {
    std::vector<std::string> amb_candidates = {"ambiguous_param", "AmBivalent", "candidate", "Ambidextrous"};
    std::string substring = "amb";
    int count = countSubstringMatches(amb_candidates, substring);

    std::cout << "Count of strings containing the substring: " << count << std::endl;

    return 0;
}
