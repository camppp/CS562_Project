#include <iostream>
#include <string>
#include <vector>

class File;
class Directory;

class PathVisitor {
public:
    virtual void visitFile(const File& file) = 0;
    virtual void visitDirectory(const Directory& directory) = 0;
};

class File {
public:
    void accept(PathVisitor* visitor) const {
        visitor->visitFile(*this);
    }
};

class Directory {
private:
    std::vector<File> files;
    std::vector<Directory> subDirectories;
public:
    void accept(PathVisitor* visitor) const {
        visitor->visitDirectory(*this);
        for (const auto& file : files) {
            file.accept(visitor);
        }
        for (const auto& subDir : subDirectories) {
            subDir.accept(visitor);
        }
    }

    void addFile(const File& file) {
        files.push_back(file);
    }

    void addSubDirectory(const Directory& directory) {
        subDirectories.push_back(directory);
    }
};

class ListVisitor : public PathVisitor {
public:
    void visitFile(const File& file) override {
        std::cout << "File: " << "file_name" << std::endl; // Replace "file_name" with actual file name
    }

    void visitDirectory(const Directory& directory) override {
        std::cout << "Directory: " << "directory_name" << std::endl; // Replace "directory_name" with actual directory name
    }
};

class SearchVisitor : public PathVisitor {
private:
    std::string targetName;
    bool found = false;
public:
    SearchVisitor(const std::string& name) : targetName(name) {}

    void visitFile(const File& file) override {
        if (file.getName() == targetName) { // Implement getName() method in File class to retrieve file name
            std::cout << "File found: " << targetName << std::endl;
            found = true;
        }
    }

    void visitDirectory(const Directory& directory) override {
        if (directory.getName() == targetName) { // Implement getName() method in Directory class to retrieve directory name
            std::cout << "Directory found: " << targetName << std::endl;
            found = true;
        }
    }

    bool isFound() const {
        return found;
    }
};

int main() {
    Directory rootDir;
    File file1, file2;
    Directory subDir;

    rootDir.addFile(file1);
    rootDir.addFile(file2);
    rootDir.addSubDirectory(subDir);

    ListVisitor listVisitor;
    rootDir.accept(&listVisitor);

    SearchVisitor searchVisitor("file2");
    rootDir.accept(&searchVisitor);
    if (!searchVisitor.isFound()) {
        std::cout << "File not found" << std::endl;
    }

    return 0;
}
