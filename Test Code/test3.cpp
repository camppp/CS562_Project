#include <iostream>
#include <unordered_map>

class ConfigVariable {
public:
    std::string name;
    std::string type;
    std::string description;
    
    ConfigVariable(std::string name, std::string type, std::string description) 
        : name(name), type(type), description(description) {}
};

class ConfigManager {
private:
    std::unordered_map<std::string, ConfigVariable> variables;

public:
    void addVariable(const ConfigVariable& variable) {
        variables[variable.name] = variable;
    }

    std::string getDescription(const std::string& name) {
        if (variables.find(name) != variables.end()) {
            return variables[name].description;
        }
        return "Variable not found";
    }
};

int main() {
    ConfigManager manager;
    
    ConfigVariable exclude_texture_scale("exclude-texture-scale", "string",
        "This is a list of glob patterns for texture filenames "
        "(excluding the directory part of the filename, but including "
        "the extension); for instance, 'digits_*.png'.  Any texture "
        "filenames that match one of these patterns will not be affected "
        "by max-texture-dimension or texture-scale.");
    
    ConfigVariable keep_texture_ram("keep-texture-ram", "boolean",
        "Specifies whether to keep the texture data in RAM after loading.");
    
    manager.addVariable(exclude_texture_scale);
    manager.addVariable(keep_texture_ram);
    
    std::cout << manager.getDescription("exclude-texture-scale") << std::endl; // Output: Description of exclude-texture-scale
    std::cout << manager.getDescription("keep-texture-ram") << std::endl; // Output: Description of keep-texture-ram
    std::cout << manager.getDescription("non-existent-variable") << std::endl; // Output: Variable not found
    
    return 0;
}
