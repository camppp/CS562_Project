#include <iostream>
#include <map>
#include <string>

class NamespaceManager {
public:
    // Create a new namespace with the given name
    void createNamespace(const std::string& name) {
        namespaces_.emplace(name, std::map<std::string, std::string>());
    }

    // Add a key-value pair to the specified namespace
    void addEntry(const std::string& namespaceName, const std::string& key, const std::string& value) {
        auto& namespaceMap = namespaces_.at(namespaceName);
        namespaceMap.emplace(key, value);
    }

    // Retrieve the value associated with the given key in the specified namespace
    std::string getEntry(const std::string& namespaceName, const std::string& key) {
        auto& namespaceMap = namespaces_.at(namespaceName);
        return namespaceMap.at(key);
    }

    // Update the value associated with the given key in the specified namespace
    void updateEntry(const std::string& namespaceName, const std::string& key, const std::string& value) {
        auto& namespaceMap = namespaces_.at(namespaceName);
        namespaceMap[key] = value;
    }

    // Delete the key-value pair with the given key from the specified namespace
    void deleteEntry(const std::string& namespaceName, const std::string& key) {
        auto& namespaceMap = namespaces_.at(namespaceName);
        namespaceMap.erase(key);
    }

private:
    std::map<std::string, std::map<std::string, std::string>> namespaces_;
};
