#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <cctype>

namespace mirrage::asset {
    int countWordOccurrences(const std::string& directory, const std::string& targetWord) {
        int totalOccurrences = 0;
        std::filesystem::path dirPath(directory);

        for (const auto& entry : std::filesystem::recursive_directory_iterator(dirPath)) {
            if (entry.is_regular_file()) {
                std::ifstream file(entry.path());
                if (file.is_open()) {
                    std::string word;
                    while (file >> word) {
                        // Convert word and targetWord to lowercase for case-insensitive comparison
                        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
                        std::string lowercaseTargetWord = targetWord;
                        std::transform(lowercaseTargetWord.begin(), lowercaseTargetWord.end(), lowercaseTargetWord.begin(), ::tolower);

                        // Remove non-alphabetic characters from the word
                        word.erase(std::remove_if(word.begin(), word.end(), [](char c) { return !std::isalpha(c); }), word.end());

                        if (word == lowercaseTargetWord) {
                            totalOccurrences++;
                        }
                    }
                    file.close();
                }
            }
        }
        return totalOccurrences;
    }
} // namespace mirrage::asset
