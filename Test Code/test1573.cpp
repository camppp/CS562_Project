#include <iostream>
#include <string>
#include <unordered_map>

class StringInt64MapManager {
public:
    StringInt64MapManager() {
        // Initialize the mapping data structure
        mapping = std::unordered_map<std::string, int64_t>();
    }

    void addMapping(const std::string& key, int64_t value) {
        // Add the new mapping to the data structure
        mapping[key] = value;
    }

    bool getValue(const std::string& key, int64_t& value) {
        // Check if the key exists in the data structure
        auto it = mapping.find(key);
        if (it != mapping.end()) {
            // Return the value associated with the key
            value = it->second;
            return true;
        } else {
            return false;
        }
    }

    bool removeMapping(const std::string& key) {
        // Check if the key exists in the data structure
        auto it = mapping.find(key);
        if (it != mapping.end()) {
            // Remove the mapping from the data structure
            mapping.erase(it);
            return true;
        } else {
            return false;
        }
    }

    void clearMappings() {
        // Clear all mappings in the data structure
        mapping.clear();
    }

private:
    // Mapping data structure
    std::unordered_map<std::string, int64_t> mapping;
};
