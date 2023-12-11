#include "../../Utils/Configuration.hpp"

class ConfigurationParser {
public:
    ConfigurationParser(const std::string& filePath) {
        // Read the configuration file and parse its contents
        std::ifstream file(filePath);
        std::string line;
        while (std::getline(file, line)) {
            // Ignore comments and whitespace lines
            if (line.empty() || line[0] == '#') {
                continue;
            }

            // Parse the key-value pair
            std::string key, value;
            std::istringstream iss(line);
            iss >> key >> value;

            // Add the key-value pair to the map
            configMap[key] = value;
        }
    }

    std::string getValue(const std::string& key) {
        // Return the value associated with the given key, or null if the key does not exist
        auto it = configMap.find(key);
        if (it != configMap.end()) {
            return it->second;
        } else {
            return nullptr;
        }
    }

private:
    std::map<std::string, std::string> configMap;
};
