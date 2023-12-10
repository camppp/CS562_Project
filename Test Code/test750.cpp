#include <iostream>
#include <string>
#include <vector>

// Class to represent an attribute
class Attribute {
public:
    std::string name;
    std::string type;
    // Other properties of an attribute can be added here
};

// Class to represent metadata for a class
class ClassMetadata {
public:
    std::string name;
    bool isInnerClass;
    std::vector<Attribute> attributes;
    std::vector<ClassMetadata> innerClasses;
};

// Class to manage class metadata registration
class MetadataRegistry {
private:
    std::vector<ClassMetadata> registeredClasses;

public:
    // Register a class with a given name
    void registerClass(const std::string& className, bool isInnerClass = false) {
        ClassMetadata newClass;
        newClass.name = className;
        newClass.isInnerClass = isInnerClass;
        registeredClasses.push_back(newClass);
    }

    // Register an inner class within a registered class
    void registerInnerClass(const std::string& parentClassName, const std::string& innerClassName) {
        for (auto& cls : registeredClasses) {
            if (cls.name == parentClassName) {
                ClassMetadata innerClass;
                innerClass.name = innerClassName;
                innerClass.isInnerClass = true;
                cls.innerClasses.push_back(innerClass);
                return;
            }
        }
        std::cerr << "Error: Parent class " << parentClassName << " not found." << std::endl;
    }

    // Add attributes to the registered classes
    void addAttribute(const std::string& className, const std::string& attributeName, const std::string& attributeType) {
        for (auto& cls : registeredClasses) {
            if (cls.name == className) {
                Attribute newAttribute;
                newAttribute.name = attributeName;
                newAttribute.type = attributeType;
                cls.attributes.push_back(newAttribute);
                return;
            }
        }
        std::cerr << "Error: Class " << className << " not found." << std::endl;
    }

    // Other operations for accessing and manipulating metadata can be added here
};

int main() {
    MetadataRegistry registry;

    // Register a class
    registry.registerClass("domGlsl_surface_type::domGenerator::domName", true);

    // Register an inner class
    registry.registerInnerClass("domGlsl_surface_type::domGenerator::domName", "InnerClassName");

    // Add an attribute to the registered class
    registry.addAttribute("domGlsl_surface_type::domGenerator::domName", "_value", "xsNCName");

    return 0;
}
