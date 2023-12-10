string find_resource_file(const string& directory_path, const string& file_name) {
    // Check if the file exists in the given directory
    if (file_exists(directory_path, file_name)) {
        return directory_path + "/" + file_name;
    }

    // Check if the file exists in any of the child directories
    for (const auto& child : get_child_directories(directory_path)) {
        string file_path = find_resource_file(child, file_name);
        if (!file_path.empty()) {
            return file_path;
        }
    }

    // If the file was not found in the given directory or any of its child directories, return an empty string
    return "";
}

bool file_exists(const string& directory_path, const string& file_name) {
    // Check if the file exists in the given directory
    if (file_exists(directory_path + "/" + file_name)) {
        return true;
    }

    // Check if the file exists in any of the child directories
    for (const auto& child : get_child_directories(directory_path)) {
        if (file_exists(child + "/" + file_name)) {
            return true;
        }
    }

    // If the file was not found in the given directory or any of its child directories, return false
    return false;
}

vector<string> get_child_directories(const string& directory_path) {
    // Get a list of all child directories in the given directory
    vector<string> child_directories;
    for (const auto& entry : fs::directory_iterator(directory_path)) {
        if (fs::is_directory(entry.path())) {
            child_directories.push_back(entry.path().string());
        }
    }
    return child_directories;
}
