#include <iostream>
#include <string>
#include <filesystem>

int countFilesWithExtension(const std::filesystem::path& directory, const std::string& extension) {
    int count = 0;
    for (const auto& entry : std::filesystem::recursive_directory_iterator(directory)) {
        if (entry.is_regular_file() && entry.path().extension() == "." + extension) {
            count++;
        }
    }
    return count;
}

int main() {
    std::string directoryPath = "C:/Users/Username/Documents";
    std::string fileExtension = "txt";
    int fileCount = countFilesWithExtension(directoryPath, fileExtension);
    std::cout << "Total files with extension " << fileExtension << ": " << fileCount << std::endl;
    return 0;
}
