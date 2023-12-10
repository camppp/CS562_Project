#include <iostream>
#include <fstream>
#include <set>
#include <filesystem>

namespace fs = std::filesystem;

// Assume the definition of the Entity class
class Entity {
    // Implementation details of the Entity class
};

class Storage {
    // Assume the definition of the Storage class
};

class IDGenerator {
    // Assume the definition of the IDGenerator class
};

class SeparateFileStorage : public Storage, public IDGenerator {
    fs::path dirPath_;
    std::set<std::string> entityIDs_;
    size_t nextID_;

public:
    using Ptr = std::shared_ptr<SeparateFileStorage>;

    SeparateFileStorage(const fs::path& dirPath) : dirPath_(dirPath), nextID_(1) {
        if (!fs::is_directory(dirPath)) {
            throw std::invalid_argument("Provided path is not a directory");
        }
    }

    std::string issueEntityID() {
        std::string newID;
        do {
            newID = std::to_string(nextID_++);
        } while (entityIDs_.count(newID) > 0);
        entityIDs_.insert(newID);
        return newID;
    }

    void saveEntity(const std::string& entityID, const Entity& entity) {
        fs::path filePath = dirPath_ / (entityID + ".dat");
        std::ofstream file(filePath);
        if (file.is_open()) {
            // Write entity data to the file
            file << "Entity data for ID: " << entityID;
            file.close();
        } else {
            throw std::runtime_error("Failed to save entity to file");
        }
    }

    Entity loadEntity(const std::string& entityID) {
        fs::path filePath = dirPath_ / (entityID + ".dat");
        if (fs::exists(filePath)) {
            std::ifstream file(filePath);
            if (file.is_open()) {
                // Read entity data from the file and construct the Entity object
                std::string entityData;
                file >> entityData;
                file.close();
                return Entity(entityData);  // Assuming a constructor for Entity from data
            } else {
                throw std::runtime_error("Failed to load entity from file");
            }
        } else {
            throw std::invalid_argument("Entity with ID " + entityID + " does not exist");
        }
    }
};
