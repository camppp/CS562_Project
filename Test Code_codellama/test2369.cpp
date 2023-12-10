#include <iostream>
#include <string>
#include <map>
#include <sstream>

std::map<std::string, int> countWordFrequency(const std::string& text) {
    std::map<std::string, int> wordFrequency;
    std::istringstream iss(text);
    std::string word;

    while (iss >> word) {
        wordFrequency[word]++;
    }

    return wordFrequency;
}

int main() {
    std::string text = "the cat in the hat";
    std::map<std::string, int> frequencyMap = countWordFrequency(text);

    for (const auto& pair : frequencyMap) {
        std::cout << pair.first << " : " << pair.second << std::endl;
    }

    return 0;
}
