c
FileInfo FileSystemLookup(const char* path) {
    // Iterate through the BootStrapFilePaths array
    for (int i = 0; i < BootStrapFilePaths.size(); i++) {
        // Check if the input path matches any of the paths for language variations
        if (strcmp(path, BootStrapFilePaths[i]) == 0) {
            // Open the corresponding file using the DVDOpen function
            FileInfo fileInfo = DVDOpen(path);
            if (fileInfo.isOpen) {
                // Return the file info structure if the file was successfully opened
                return fileInfo;
            }
        }
    }

    // If no matching path is found, return an appropriate error code
    return FileInfo{};
}
