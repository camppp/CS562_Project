#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>

int countSubstringMatches(const std::vector<std::string>& amb_candidates, const std::string& substring) {
    int count = 0;
    for (const std::string& str : amb_candidates) {
        std::string lower_str = str;
        std::transform(lower_str.begin(), lower_str.end(), lower_str.begin(), ::tolower);
        std::string lower_substring = substring;
        std::transform(lower_substring.begin(), lower_substring.end(), lower_substring.begin(), ::tolower);
        if (lower_str.find(lower_substring)!= std::string::npos) {
            count++;
        }
    }
    return count;
}

int main() {
    std::vector<std::string> amb_candidates = {"ambiguous_param", "AmBivalent", "candidate", "Ambidextrous"};
    std::string substring = "amb";
    int count = countSubstringMatches(amb_candidates, substring);
    std::cout << "Count of strings containing the substring: " << count << std::endl;
    return 0;
}