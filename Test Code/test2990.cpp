#include <iostream>
#include <vector>

class pstring {
public:
    static bool checkExtension(const std::string& filename, const std::string& extension) {
        size_t dotPos = filename.find_last_of(".");
        if (dotPos != std::string::npos) {
            std::string fileExt = filename.substr(dotPos + 1);
            return fileExt == extension;
        }
        return false;
    }
};

class pfile {
public:
    static bool copy(const std::string& source, const std::string& destination) {
        // Implement file copy logic here
        // Return true if the file is successfully copied, false otherwise
        return true;  // Placeholder return value
    }
};

void save(const std::vector<std::string>& parm) {
    if (pstring::checkExtension(parm[1], "txt")) {
        if (pfile::copy(recordfilepath, parm[1])) {
            std::cout << "File: " << parm[1] << " created successfully.\n";
        }
        else {
            std::cerr << "Failed:" << parm[1] << " write failed.\n";
        }
    }
}

int main() {
    // Example usage
    std::vector<std::string> params = {"param1", "file.txt"};
    save(params);
    return 0;
}
