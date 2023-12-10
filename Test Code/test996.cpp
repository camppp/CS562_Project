#include <iostream>
#include <string>

class FileAsset {
private:
    std::string path;

public:
    void setPath(const std::string& newPath) {
        if (!newPath.empty()) {
            path = newPath;
        } else {
            std::cout << "Error: File path cannot be empty." << std::endl;
        }
    }

    std::string getPath() const {
        return path;
    }
};

int main() {
    FileAsset* newAsset = new FileAsset();
    newAsset->setPath("example/file/path.txt");
    std::cout << "File path: " << newAsset->getPath() << std::endl;

    newAsset->setPath(""); // This should produce an error message
    std::cout << "File path: " << newAsset->getPath() << std::endl; // Should still be the previous path

    delete newAsset;
    return 0;
}
