#include <iostream>
#include <string>
#include <unordered_map>

class properties {
private:
    std::unordered_map<std::string, std::string> mProperties;
    std::string mNamespace;
    std::string mClass;
    std::string mName;

public:
    // Default constructor
    properties() : mProperties(), mNamespace(""), mClass(""), mName("") {}

    // Parameterized constructor
    properties(const std::string& ns, const std::string& clas, const std::string& instance)
        : mProperties(), mNamespace(ns), mClass(clas), mName(instance) {}

    // Method to add a new property
    void addProperty(const std::string& key, const std::string& value) {
        mProperties[key] = value;
    }

    // Method to retrieve the value of a property
    std::string getProperty(const std::string& key) {
        if (mProperties.find(key) != mProperties.end()) {
            return mProperties[key];
        } else {
            return "Property not found";
        }
    }

    // Method to update the value of an existing property
    void updateProperty(const std::string& key, const std::string& value) {
        if (mProperties.find(key) != mProperties.end()) {
            mProperties[key] = value;
        } else {
            std::cout << "Property not found" << std::endl;
        }
    }

    // Method to remove a property
    void removeProperty(const std::string& key) {
        if (mProperties.find(key) != mProperties.end()) {
            mProperties.erase(key);
        } else {
            std::cout << "Property not found" << std::endl;
        }
    }
};

int main() {
    // Example usage
    properties obj("namespace1", "class1", "instance1");
    obj.addProperty("key1", "value1");
    std::cout << obj.getProperty("key1") << std::endl;  // Output: value1
    obj.updateProperty("key1", "new_value");
    std::cout << obj.getProperty("key1") << std::endl;  // Output: new_value
    obj.removeProperty("key1");
    std::cout << obj.getProperty("key1") << std::endl;  // Output: Property not found
    return 0;
}
