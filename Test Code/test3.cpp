class ConfigVariable {
public:
    std::string name;
    std::string type;
    std::string description;
    
    ConfigVariable(std::string name, std::string type, std::string description) 
        : name(name), type(type), description(description) {}
    
    std::string getDescription(std::string name) {
        for (auto& variable : variables) {
            if (variable.name == name) {
                return variable.description;
            }
        }
        return "Variable not found";
    }
};

// Example usage
ConfigVariable exclude_texture_scale("exclude-texture-scale", "string",
    "This is a list of glob patterns for texture filenames "
    "(excluding the directory part of the filename, but including "
    "the extension); for instance, 'digits_*.png'.  Any texture "
    "filenames that match one of these patterns will not be affected "
    "by max-texture-dimension or texture-scale.");

ConfigVariable keep_texture_ram("keep-texture-ram", "boolean",
    "Specifies whether to keep the texture data in RAM after loading.");

int main() {
    std::string name = "exclude-texture-scale";
    std::string description = ConfigVariable::getDescription(name);
    std::cout << "Description of " << name << ": " << description << std::endl;
    return 0;
}
