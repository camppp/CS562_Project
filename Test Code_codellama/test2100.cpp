#include <iostream>
#include <string>
#include <filesystem>

int main() {
    // Get the directory path and file extension from the user
    std::string directory_path;
    std::string file_extension;
    std::cout << "Enter the directory path: ";
    std::cin >> directory_path;
    std::cout << "Enter the file extension: ";
    std::cin >> file_extension;

    // Check if the directory path is valid and the file extension is non-empty
    if (!std::filesystem::exists(directory_path)) {
        std::cout << "Invalid directory path" << std::endl;
        return 1;
    }
    if (file_extension.empty()) {
        std::cout << "Invalid file extension" << std::endl;
        return 1;
    }

    // Traverse the directory and its subdirectories to count the number of files with the given extension
    int file_count = 0;
    for (const auto& entry : std::filesystem::recursive_directory_iterator(directory_path)) {
        if (entry.path().extension() == file_extension) {
            file_count++;
        }
    }

    // Output the total count of files with the specified extension
    std::cout << "Total number of files with extension " << file_extension << ": " << file_count << std::endl;

    return 0;
}
