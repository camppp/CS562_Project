#include <iostream>
#include <vector>
#include <string>
#include <filesystem>

std::vector<std::string> getFilesList(const std::string& directory) {
    std::vector<std::string> filesList;

    for (const auto& entry : std::filesystem::directory_iterator(directory)) {
        if (entry.is_regular_file()) {
            filesList.push_back(entry.path().string());
        } else if (entry.is_directory()) {
            std::vector<std::string> subDirFiles = getFilesList(entry.path().string());
            filesList.insert(filesList.end(), subDirFiles.begin(), subDirFiles.end());
        }
    }

    return filesList;
}

int main() {
    std::string directoryPath = "path_to_directory";  // Replace with the actual directory path
    std::vector<std::string> allFiles = getFilesList(directoryPath);

    std::cout << "Files found in directory and subdirectories:" << std::endl;
    for (const auto& file : allFiles) {
        std::cout << file << std::endl;
    }

    return 0;
}
