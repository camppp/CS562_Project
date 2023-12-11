#include <string>
#include <algorithm>

int countWordOccurrences(const std::string& text, const std::string& word)
{
    // Convert the input text and word to lowercase
    std::string text_lower = std::string(text).toLower();
    std::string word_lower = std::string(word).toLower();

    // Count the number of occurrences of the word in the text
    int count = 0;
    for (int i = 0; i < text_lower.size(); i++)
    {
        if (text_lower.substr(i, word_lower.size()) == word_lower)
        {
            count++;
        }
    }

    return count;
}
