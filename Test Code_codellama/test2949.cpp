fs::path DirectoryUtils::searchResourceDirectory(const fs::path& workingDirectory) {
    // Check if the working directory is a resource directory
    if (fs::is_directory(workingDirectory)) {
        return workingDirectory;
    }

    // Traverse the directory structure to find the resource directory
    for (const auto& entry : fs::directory_iterator(workingDirectory)) {
        if (fs::is_directory(entry)) {
            // Check if the entry is a resource directory
            if (fs::is_directory(entry / "resources")) {
                return entry / "resources";
            }
        }
    }

    // If the resource directory is not found, return an empty path
    return fs::path();
}
