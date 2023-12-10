#include <iostream>
#include <vector>
#include <string>

class ConfigFile {
public:
    std::vector<std::string> config_names;
    std::vector<std::string> config_values;

    void addConfig(const std::string& name, const std::string& value) {
        // Add the configuration name and value to the respective vectors
        config_names.push_back(name);
        config_values.push_back(value);
    }

    std::string getValue(const std::string& name) {
        // Retrieve the value associated with the given configuration name
        for (size_t i = 0; i < config_names.size(); ++i) {
            if (config_names[i] == name) {
                return config_values[i];
            }
        }
        return "Not found";
    }
};

ConfigFile createConfigFile(const std::vector<std::string>& names, const std::vector<std::string>& values) {
    // Create a ConfigFile object from the given configuration names and values
    ConfigFile out;
    for (size_t i = 0; i < names.size(); ++i) {
        out.addConfig(names[i], values[i]);
    }
    return out;
}

int main() {
    // Example usage
    std::vector<std::string> names = {"failed", "timeout", "max_attempts"};
    std::vector<std::string> values = {"true", "30", "5"};

    ConfigFile configFile = createConfigFile(names, values);

    std::cout << "Value for 'failed': " << configFile.getValue("failed") << std::endl;  // Output: true
    std::cout << "Value for 'timeout': " << configFile.getValue("timeout") << std::endl;  // Output: 30
    std::cout << "Value for 'max_attempts': " << configFile.getValue("max_attempts") << std::endl;  // Output: 5

    return 0;
}
