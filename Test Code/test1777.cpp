#include <iostream>
#include <vector>
#include <algorithm>

bool isShorter(const std::string &s1, const std::string &s2) {
    return s1.size() < s2.size();
}

void elimDups(std::vector<std::string> &words) {
    std::sort(words.begin(), words.end());
    auto end_unique = std::unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

int main() {
    std::vector<std::string> story = { "the", "quick", "red", "fox", "jump", "over", "the", "slow", "red", "turtle" };
    elimDups(story);
    for(const auto &s : story)
        std::cout << s << " ";
    std::cout << std::endl;
    std::stable_sort(story.begin(), story.end(), isShorter);
    for(const auto &s : story)
        std::cout << s << " ";
    std::cout << std::endl;
    return 0;
}
