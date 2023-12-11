#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int countSubstringMatches(const std::vector<std::string>& amb_candidates, const std::string& substring) {
    int count = 0;
    for (const auto& candidate : amb_candidates) {
        if (candidate.find(substring, 0, std::locale("en_US.UTF-8")) != std::string::npos) {
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
