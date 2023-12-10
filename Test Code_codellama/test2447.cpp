#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>

class File {
public:
    File(const std::string& path) : path_(path) {}

    void write(const std::string& data) {
        std::ofstream out(path_, std::ios::binary);
        out << data;
    }

    void read(std::string& data) {
        std::ifstream in(path_, std::ios::binary);
        in >> data;
    }

private:
    std::string path_;
};

class ResourceManager {
public:
    ResourceManager() {}

    ~ResourceManager() {
        for (auto& file : files_) {
            file->close();
        }
    }

    void addFile(const std::string& path) {
        files_.push_back(std::make_unique<File>(path));
    }

    void removeFile(const std::string& path) {
        for (auto it = files_.begin(); it != files_.end(); ++it) {
            if ((*it)->path_ == path) {
                files_.erase(it);
                break;
            }
        }
    }

    std::unique_ptr<File> getFile(const std::string& path) {
        for (auto& file : files_) {
            if (file->path_ == path) {
                return std::move(file);
            }
        }
        return nullptr;
    }

private:
    std::vector<std::unique_ptr<File>> files_;
};

class OnScopeExit {
public:
    OnScopeExit(ResourceManager& manager, const std::string& path) : manager_(manager), path_(path) {}

    ~OnScopeExit() {
        manager_.removeFile(path_);
    }

private:
    ResourceManager& manager_;
    std::string path_;
};

std::unique_ptr<File> getUtf32To8WriteResource(const std::string& path) {
    return std::make_unique<File>(path);
}

void utf32To8WriteResource(const std::string& path, const std::string& data) {
    auto file = getUtf32To8WriteResource(path);
    file->write(data);
}

int main() {
    ResourceManager manager;
    std::string path = "example.txt";
    manager.addFile(path);

    {
        OnScopeExit onScopeExit(manager, path);
        utf32To8WriteResource(path, "Hello, world!");
    }

    return 0;
}
