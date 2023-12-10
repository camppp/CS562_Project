#include <iostream>
#include <map>
#include <string>

class ClassMetadata {
public:
    // Register a class with a given name
    void registerClass(const std::string& name) {
        classes_[name] = Class();
    }

    // Register an inner class within a registered class
    void registerInnerClass(const std::string& outerClass, const std::string& innerClass) {
        classes_[outerClass].innerClasses_.push_back(innerClass);
    }

    // Add attributes to the registered classes
    void addAttribute(const std::string& className, const std::string& attributeName) {
        classes_[className].attributes_.push_back(attributeName);
    }

    // Get the list of registered classes
    std::vector<std::string> getClasses() {
        std::vector<std::string> classes;
        for (const auto& class_ : classes_) {
            classes.push_back(class_.first);
        }
        return classes;
    }

    // Get the list of inner classes for a given class
    std::vector<std::string> getInnerClasses(const std::string& className) {
        return classes_[className].innerClasses_;
    }

    // Get the list of attributes for a given class
    std::vector<std::string> getAttributes(const std::string& className) {
        return classes_[className].attributes_;
    }

private:
    struct Class {
        std::vector<std::string> innerClasses_;
        std::vector<std::string> attributes_;
    };

    std::map<std::string, Class> classes_;
};

int main() {
    ClassMetadata metadata;

    // Register a class
    metadata.registerClass("MyClass");

    // Register an inner class
    metadata.registerInnerClass("MyClass", "InnerClass");

    // Add attributes to the registered classes
    metadata.addAttribute("MyClass", "attribute1");
    metadata.addAttribute("MyClass", "attribute2");

    // Get the list of registered classes
    std::vector<std::string> classes = metadata.getClasses();
    for (const auto& class_ : classes) {
        std::cout << class_ << std::endl;
    }

    // Get the list of inner classes for a given class
    std::vector<std::string> innerClasses = metadata.getInnerClasses("MyClass");
    for (const auto& innerClass : innerClasses) {
        std::cout << innerClass << std::endl;
    }

    // Get the list of attributes for a given class
    std::vector<std::string> attributes = metadata.getAttributes("MyClass");
    for (const auto& attribute : attributes) {
        std::cout << attribute << std::endl;
    }

    return 0;
}
