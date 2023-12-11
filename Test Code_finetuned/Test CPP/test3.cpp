class ConfigVariable:
    def __init__(self, name, type, description):
        self.name = name
        self.type = type
        self.description = description

class ConfigVariableManager:
    def __init__(self):
        self.variables = {}

    def add_variable(self, variable):
        self.variables[variable.name] = variable

    def get_description(self, name):
        if name in self.variables:
            return self.variables[name].description
        else:
            return "Variable not found"

# Example usage
manager = ConfigVariableManager()
manager.add_variable(ConfigVariable("exclude-texture-scale", "string", "This is a list of glob patterns for texture filenames (excluding the directory part of the filename, but including the extension); for instance, 'digits_*.png'. Any texture filenames that match one of these patterns will not be affected by max-texture-dimension or texture-scale."))
manager.add_variable(ConfigVariable("keep-texture-ram", "boolean", "Specifies whether to keep the texture data in RAM after loading."))

print(manager.get_description("exclude-texture-scale"))
print(manager.get_description("keep-texture-ram"))
print(manager.get_description("nonexistent-variable"))