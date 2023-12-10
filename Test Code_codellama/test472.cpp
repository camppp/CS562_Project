#include <iostream>
#include <string>
#include <vector>

bool isFileAcceptable(const std::string& fileName, const std::vector<std::string>& fileFilters) {
    // If no file filters are provided, all files are considered acceptable
    if (fileFilters.empty()) {
        return true;
    }

    // Get the file suffix
    std::string suffix = fileName.substr(fileName.find_last_of('.') + 1);

    // Convert the suffix to lowercase
    std::transform(suffix.begin(), suffix.end(), suffix.begin(), ::tolower);

    // Check if the suffix is in the list of acceptable suffixes
    return std::find(fileFilters.begin(), fileFilters.end(), suffix) != fileFilters.end();
}
