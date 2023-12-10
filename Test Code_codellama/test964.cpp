bool searchFilePath(const char* path, const Iom& defaultIom) {
    // Check if the path is an absolute path
    if (path[0] == '/') {
        // If the path is absolute, use it as is
        return defaultIom.getSearchDirectory() == path;
    } else {
        // If the path is relative, concatenate it with the default search directory
        std::string searchPath = defaultIom.getSearchDirectory() + path;
        // Check if the concatenated path exists
        return std::filesystem::exists(searchPath);
    }
}
