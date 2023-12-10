#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int countSubstringMatches(const std::vector<std::string>& amb_candidates, const std::string& substring) {
    int count = 0;
    std::string lowerSubstring = substring;
    std::transform(lowerSubstring.begin(), lowerSubstring.end(), lowerSubstring.begin(), ::tolower);

    for (const std::string& candidate : amb_candidates) {
        std::string lowerCandidate = candidate;
        std::transform(lowerCandidate.begin(), lowerCandidate.end(), lowerCandidate.begin(), ::tolower);
        if (lowerCandidate.find(lowerSubstring) != std::string::npos) {
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
