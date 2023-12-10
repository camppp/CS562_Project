#include <iostream>
#include <unordered_map>
#include <vector>

std::string makeKey(const std::string& s) {
    std::unordered_map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }
    std::string key;
    for (const auto& p : freq) {
        key += std::to_string(p.second) + p.first;
    }
    return key;
}

std::unordered_map<std::string, std::vector<std::string>> groupStrings(const std::vector<std::string>& strings) {
    std::unordered_map<std::string, std::vector<std::string>> map;
    for (const std::string& s : strings) {
        std::string key = makeKey(s);
        map[key].push_back(s);
    }
    return map;
}

int main() {
    std::vector<std::string> input = {"abc", "bca", "cab", "def", "fed"};
    std::unordered_map<std::string, std::vector<std::string>> result = groupStrings(input);
    for (const auto& entry : result) {
        std::cout << entry.first << ": ";
        for (const std::string& s : entry.second) {
            std::cout << s << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
