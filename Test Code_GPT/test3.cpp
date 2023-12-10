#include <iostream>
#include <vector>

class ConfigVariable {
public:
    std::string name;
    std::string type;
    std::string description;

    ConfigVariable(std::string name, std::string type, std::string description)
        : name(name), type(type), description(description) {}

    static std::string getDescription(const std::vector<ConfigVariable>& configVariables, const std::string& variableName);
};

std::string ConfigVariable::getDescription(const std::vector<ConfigVariable>& configVariables, const std::string& variableName) {
    for (const auto& variable : configVariables) {
        if (variable.name == variableName) {
            return variable.description;
        }
    }
    return "Variable not found";
}

int main() {
    // Example usage
    std::vector<ConfigVariable> configVariables = {
        ConfigVariable("exclude-texture-scale", "string", "This is a list of glob patterns for texture filenames "
                                                         "(excluding the directory part of the filename, but including "
                                                         "the extension); for instance, 'digits_*.png'. Any texture "
                                                         "filenames that match one of these patterns will not be affected "
                                                         "by max-texture-dimension or texture-scale."),
        ConfigVariable("keep-texture-ram", "boolean", "Specifies whether to keep the texture data in RAM after loading.")
    };

    // Retrieving descriptions
    std::cout << ConfigVariable::getDescription(configVariables, "exclude-texture-scale") << std::endl;
    std::cout << ConfigVariable::getDescription(configVariables, "keep-texture-ram") << std::endl;
    std::cout << ConfigVariable::getDescription(configVariables, "non-existent-variable") << std::endl;

    return 0;
}
