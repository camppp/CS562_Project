#include <vector>
#include <string>
#include <algorithm>

int countSmallestCharFrequency(const std::string& str) {
    char smallestChar = 'z';
    int frequency = 0;
    for (char c : str) {
        if (c < smallestChar) {
            smallestChar = c;
            frequency = 1;
        } else if (c == smallestChar) {
            frequency++;
        }
    }
    return frequency;
}

std::vector<int> compareQueries(std::vector<std::string>& queries, std::vector<std::string>& words) {
    std::vector<int> result;
    std::vector<int> wordFrequencies;
    for (const auto& word : words) {
        wordFrequencies.push_back(countSmallestCharFrequency(word));
    }
    std::sort(wordFrequencies.begin(), wordFrequencies.end());
    for (const auto& query : queries) {
        int queryFrequency = countSmallestCharFrequency(query);
        auto it = std::upper_bound(wordFrequencies.begin(), wordFrequencies.end(), queryFrequency);
        result.push_back(wordFrequencies.end() - it);
    }
    return result;
}
