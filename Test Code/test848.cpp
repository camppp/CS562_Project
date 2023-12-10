#include <iostream>
#include <vector>
#include <string>

class ConfigFile {
public:
    std::vector<std::string> config_names;
    std::vector<std::string> config_values;

    void addConfig(const std::string& name, const std::string& value) {
        config_names.push_back(name);
        config_values.push_back(value);
    }

    std::string getValue(const std::string& name) {
        for (size_t i = 0; i < config_names.size(); ++i) {
            if (config_names[i] == name) {
                return config_values[i];
            }
        }
        return "Not found";
    }
};

ConfigFile createConfigFile(const std::vector<std::string>& names, const std::vector<std::string>& values) {
    ConfigFile out;
    for (size_t i = 0; i < names.size(); ++i) {
        out.addConfig(names[i], values[i]);
    }
    return out;
}
