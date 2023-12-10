#include <filesystem>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <utility>

using fs = std::filesystem;

class SeparateFileStorage {
public:
    using Ptr = std::shared_ptr<SeparateFileStorage>;

    SeparateFileStorage(const fs::path& dirPath) : dirPath_(dirPath) {
        if (!fs::exists(dirPath)) {
            throw std::runtime_error("Invalid directory path");
        }
    }

    std::string issueEntityID() {
        std::string id;
        do {
            id = generateID();
        } while (entityIDs_.find(id) != entityIDs_.end());
        entityIDs_.insert(id);
        return id;
    }

    void saveEntity(const std::string& entityID, const Entity& entity) {
        fs::path filePath = dirPath_ / entityID;
        std::ofstream file(filePath, std::ios::binary);
        if (!file.is_open()) {
            throw std::runtime_error("Failed to open file");
        }
        file << entity;
        file.close();
    }

    Entity loadEntity(const std::string& entityID) {
        fs::path filePath = dirPath_ / entityID;
        std::ifstream file(filePath, std::ios::binary);
        if (!file.is_open()) {
            throw std::runtime_error("Failed to open file");
        }
        Entity entity;
        file >> entity;
        file.close();
        return entity;
    }

private:
    fs::path dirPath_;
    std::set<std::string> entityIDs_;
    std::string generateID() {
        // Generate a unique ID using a random number
        std::string id = std::to_string(std::rand());
        // Ensure the ID is not already in use
        while (entityIDs_.find(id) != entityIDs_.end()) {
            id = std::to_string(std::rand());
        }
        return id;
    }
};
