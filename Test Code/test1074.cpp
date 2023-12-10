#include <string>
#include <vector>

std::vector<std::string> extractModelNames(const std::vector<std::string>& filePaths) {
    std::vector<std::string> modelNames;
    for (const auto& filePath : filePaths) {
        // Find the last occurrence of the forward slash
        size_t lastSlash = filePath.find_last_of('/');
        if (lastSlash == std::string::npos) {
            // If there is no forward slash, the model name is the entire file path
            modelNames.push_back(filePath);
        } else {
            // If there is a forward slash, extract the model name
            std::string modelName = filePath.substr(lastSlash + 1);
            // Check if the model name contains a hyphen
            size_t hyphenIndex = modelName.find_first_of('-');
            if (hyphenIndex != std::string::npos) {
                // If the model name contains a hyphen, split it into two parts
                modelName = modelName.substr(0, hyphenIndex);
            }
            modelNames.push_back(modelName);
        }
    }
    return modelNames;
}
