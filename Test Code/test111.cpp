#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

int countUniqueHeaderFiles(const std::vector<std::string>& includedFiles) {
    std::unordered_set<std::string> uniqueFiles;

    for (const std::string& file : includedFiles) {
        size_t pos = file.find_last_of("/\\");  // Find the last path separator
        std::string baseName = (pos == std::string::npos) ? file : file.substr(pos + 1);
        uniqueFiles.insert(baseName);
    }

    return uniqueFiles.size();
}

int main() {
    std::vector<std::string> includedFiles = {"Graphics.Layouts.h", "Common.Sounds.h", "Options.h", "Game.Descriptors.h", "Game.ScenarioDescriptors.h", "map", "Context.Editor.NewRoom.h"};
    std::cout << countUniqueHeaderFiles(includedFiles) << std::endl;  // Output: 6
    return 0;
}
