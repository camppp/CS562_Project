#include <string>
#include <vector>

std::string reverseWords(const std::string& s) {
    std::vector<std::string> words;
    std::string::size_type start = 0;
    std::string::size_type end = 0;

    // Split the input string into words
    while ((end = s.find(' ', start)) != std::string::npos) {
        words.push_back(s.substr(start, end - start));
        start = end + 1;
    }

    // Reverse the order of characters in each word
    for (auto& word : words) {
        std::reverse(word.begin(), word.end());
    }

    // Join the words back into a single string
    std::string result;
    for (auto& word : words) {
        result += word;
    }

    return result;
}
