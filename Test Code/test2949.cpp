fs::path DirectoryUtils::searchResourceDirectory(const fs::path& workingDirectory) {
    // Start the search from the working directory
    fs::path currentDirectory = workingDirectory;

    // Traverse up the directory structure until the resource directory is found
    while (!currentDirectory.empty()) {
        fs::path resourceDirectory = currentDirectory / "resources";
        if (fs::exists(resourceDirectory) && fs::is_directory(resourceDirectory)) {
            return resourceDirectory;
        }
        currentDirectory = currentDirectory.parent_path();
    }

    // If the resource directory is not found, return an empty path
    return fs::path();
}
