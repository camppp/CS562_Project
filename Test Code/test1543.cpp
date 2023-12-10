#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <stdexcept>

class NamespaceManager {
private:
    std::unordered_map<std::string, std::unordered_map<std::string, std::string>> namespaces;
    std::unordered_map<std::string, std::unordered_set<std::string>> subNamespaces;

public:
    void createNamespace(const std::string& name) {
        namespaces[name] = std::unordered_map<std::string, std::string>();
        subNamespaces[name] = std::unordered_set<std::string>();
    }

    void addVariable(const std::string& namespaceName, const std::string& varName, const std::string& value) {
        if (namespaces.find(namespaceName) != namespaces.end()) {
            namespaces[namespaceName][varName] = value;
        } else {
            throw std::invalid_argument("Namespace does not exist");
        }
    }

    std::string getVariableValue(const std::string& namespaceName, const std::string& varName) {
        if (namespaces.find(namespaceName) != namespaces.end()) {
            if (namespaces[namespaceName].find(varName) != namespaces[namespaceName].end()) {
                return namespaces[namespaceName][varName];
            } else {
                throw std::invalid_argument("Variable does not exist in the namespace");
            }
        } else {
            throw std::invalid_argument("Namespace does not exist");
        }
    }

    void createSubNamespace(const std::string& parentNamespace, const std::string& subNamespace) {
        if (namespaces.find(parentNamespace) != namespaces.end()) {
            namespaces[subNamespace] = std::unordered_map<std::string, std::string>();
            subNamespaces[parentNamespace].insert(subNamespace);
        } else {
            throw std::invalid_argument("Parent namespace does not exist");
        }
    }

    void deleteNamespace(const std::string& namespaceName) {
        if (namespaces.find(namespaceName) != namespaces.end()) {
            for (const auto& subNamespace : subNamespaces[namespaceName]) {
                deleteNamespace(subNamespace);
            }
            namespaces.erase(namespaceName);
            subNamespaces.erase(namespaceName);
        } else {
            throw std::invalid_argument("Namespace does not exist");
        }
    }
};

int main() {
    NamespaceManager manager;
    manager.createNamespace("global");
    manager.addVariable("global", "var1", "value1");
    manager.createSubNamespace("global", "local");
    manager.addVariable("local", "var2", "value2");

    std::cout << manager.getVariableValue("global", "var1") << std::endl;  // Output: value1
    std::cout << manager.getVariableValue("local", "var2") << std::endl;   // Output: value2

    manager.deleteNamespace("global");
    // manager.getVariableValue("global", "var1");  // Throws exception: Namespace does not exist
    // manager.getVariableValue("local", "var2");   // Throws exception: Namespace does not exist

    return 0;
}
