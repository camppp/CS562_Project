#include <iostream>
#include <unordered_map>
#include <stdexcept>

class NamespaceManager {
private:
    std::unordered_map<std::string, std::unordered_map<std::string, std::string>> namespaces;

public:
    void createNamespace(const std::string& namespaceName) {
        namespaces.emplace(namespaceName, std::unordered_map<std::string, std::string>());
    }

    void addEntry(const std::string& namespaceName, const std::string& key, const std::string& value) {
        if (namespaces.find(namespaceName) != namespaces.end()) {
            namespaces[namespaceName][key] = value;
        } else {
            throw std::invalid_argument("Namespace does not exist");
        }
    }

    std::string getEntry(const std::string& namespaceName, const std::string& key) {
        if (namespaces.find(namespaceName) != namespaces.end()) {
            auto& namespaceMap = namespaces[namespaceName];
            if (namespaceMap.find(key) != namespaceMap.end()) {
                return namespaceMap[key];
            } else {
                throw std::invalid_argument("Key does not exist in the namespace");
            }
        } else {
            throw std::invalid_argument("Namespace does not exist");
        }
    }

    void updateEntry(const std::string& namespaceName, const std::string& key, const std::string& value) {
        if (namespaces.find(namespaceName) != namespaces.end()) {
            auto& namespaceMap = namespaces[namespaceName];
            if (namespaceMap.find(key) != namespaceMap.end()) {
                namespaceMap[key] = value;
            } else {
                throw std::invalid_argument("Key does not exist in the namespace");
            }
        } else {
            throw std::invalid_argument("Namespace does not exist");
        }
    }

    void deleteEntry(const std::string& namespaceName, const std::string& key) {
        if (namespaces.find(namespaceName) != namespaces.end()) {
            auto& namespaceMap = namespaces[namespaceName];
            if (namespaceMap.find(key) != namespaceMap.end()) {
                namespaceMap.erase(key);
            } else {
                throw std::invalid_argument("Key does not exist in the namespace");
            }
        } else {
            throw std::invalid_argument("Namespace does not exist");
        }
    }
};

int main() {
    NamespaceManager nsManager;

    // Create a namespace
    nsManager.createNamespace("employees");

    // Add entries to the "employees" namespace
    nsManager.addEntry("employees", "001", "John Doe");
    nsManager.addEntry("employees", "002", "Jane Smith");

    // Retrieve and print an entry from the "employees" namespace
    std::cout << nsManager.getEntry("employees", "001") << std::endl;

    // Update an entry in the "employees" namespace
    nsManager.updateEntry("employees", "002", "Jane Johnson");

    // Delete an entry from the "employees" namespace
    nsManager.deleteEntry("employees", "001");

    return 0;
}
