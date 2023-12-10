#include <string>
#include <vector>

namespace sltbench {

std::string reverseWords(const std::string& input) {
    std::vector<std::string> words;
    std::string word;

    for (char c : input) {
        if (c == ' ') {
            words.push_back(word);
            word.clear();
        } else {
            word += c;
        }
    }

    if (!word.empty()) {
        words.push_back(word);
    }

    std::reverse(words.begin(), words.end());

    std::string reversed;
    for (const std::string& word : words) {
        reversed += word;
        reversed += ' ';
    }

    return reversed.substr(0, reversed.size() - 1);
}

} // namespace sltbench
