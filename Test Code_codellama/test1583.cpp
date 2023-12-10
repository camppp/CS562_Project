#include <iostream>
#include <string>
#include <cctype>

int countWordOccurrences(const std::string& text, const std::string& word) {
    int count = 0;
    for (int i = 0; i < text.size(); i++) {
        if (text[i] == word[0] && isalpha(text[i])) {
            int j = i + 1;
            while (j < text.size() && text[j] == word[j - i] && isalpha(text[j])) {
                j++;
            }
            if (j == text.size() || !isalpha(text[j])) {
                count++;
            }
        }
    }
    return count;
}
