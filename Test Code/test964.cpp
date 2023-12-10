#include <iostream>
#include <string>

class Iom {
private:
    std::string searchDirectory;

public:
    Iom(const std::string& directory) : searchDirectory(directory) {}

    const std::string& getSearchDirectory() const {
        return searchDirectory;
    }
};

bool searchFilePath(const char* path, const Iom& defaultIom) {
    // Extract the search directory from defaultIom
    std::string searchDirectory = defaultIom.getSearchDirectory();

    // Check if the path contains the search directory as a prefix
    std::string pathStr(path);
    if (pathStr.find(searchDirectory) == 0) {
        return true;  // Path found within the directory structure
    } else {
        // Path not found, display a message
        printf("Did not find path %s in %s.", path, searchDirectory.c_str());
        return false;
    }
}

int main() {
    Iom defaultIom("/home/user/documents");
    bool result1 = searchFilePath("/home/user/documents/file1.txt", defaultIom); // Should return true
    bool result2 = searchFilePath("/home/user/downloads/file2.txt", defaultIom); // Should return false

    std::cout << "Result 1: " << (result1 ? "true" : "false") << std::endl;
    std::cout << "Result 2: " << (result2 ? "true" : "false") << std::endl;

    return 0;
}
