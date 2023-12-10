#include <iostream>
#include <string>

class FileAsset {
private:
    std::string path;

public:
    // Implement the setPath function
    void setPath(const std::string& newPath) {
        if (!newPath.empty()) {
            path = newPath;
        } else {
            std::cout << "Error: File path cannot be empty." << std::endl;
        }
    }

    // Getter for path (for testing purposes)
    std::string getPath() const {
        return path;
    }
};
