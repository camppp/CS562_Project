#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

namespace mirrage::asset {
    int countWordOccurrences(const std::string& directory, const std::string& targetWord) {
        int count = 0;
        for (const auto& entry : std::filesystem::directory_iterator(directory)) {
            if (entry.is_regular_file()) {
                std::ifstream file(entry.path());
                std::string line;
                while (std::getline(file, line)) {
                    std::string word = line;
                    std::transform(word.begin(), word.end(), word.begin(), ::tolower);
                    if (word.find(targetWord) != std::string::npos) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
} // namespace mirrage::asset
