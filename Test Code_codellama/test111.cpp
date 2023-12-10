int countUniqueHeaderFiles(const std::vector<std::string>& includedFiles) {
    std::set<std::string> uniqueHeaders;
    for (const auto& file : includedFiles) {
        // Extract the base file name from the file path
        std::string baseFileName = file.substr(file.find_last_of('/') + 1);
        // Ignore any file paths and only consider the base file name for uniqueness
        uniqueHeaders.insert(baseFileName);
    }
    return uniqueHeaders.size();
}
