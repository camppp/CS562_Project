int countWordOccurrences(const std::string& text, const std::string& word) {
    int count = 0;
    std::string::size_type start = 0;
    while ((start = text.find(word, start)) != std::string::npos) {
        // Check if the word is a whole word
        if (start > 0 && !isalnum(text[start - 1])) {
            count++;
        }
        start += word.length();
    }
    return count;
}
