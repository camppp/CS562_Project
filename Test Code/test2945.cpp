#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

class Namespace {
public:
    std::string name;
    std::unordered_map<std::string, int> variables;
    std::vector<Namespace*> children;

    Namespace(const std::string& name) : name(name) {}
};

class NamespaceManager {
private:
    Namespace* root;

    Namespace* findNamespace(Namespace* current, const std::string& namespaceName) {
        if (current->name == namespaceName) {
            return current;
        }
        for (Namespace* child : current->children) {
            Namespace* found = findNamespace(child, namespaceName);
            if (found != nullptr) {
                return found;
            }
        }
        return nullptr;
    }

    int getVariableValue(Namespace* current, const std::string& variableName) {
        if (current->variables.find(variableName) != current->variables.end()) {
            return current->variables[variableName];
        }
        if (current->name != "global") {
            return getVariableValue(findNamespace(root, current->name), variableName);
        }
        return -1; // Variable not found
    }

public:
    NamespaceManager() {
        root = new Namespace("global");
    }

    void createNamespace(const std::string& namespaceName) {
        Namespace* newNamespace = new Namespace(namespaceName);
        root->children.push_back(newNamespace);
    }

    void deleteNamespace(const std::string& namespaceName) {
        // Implementation for deleting a namespace and its sub-namespaces
        // Not included for brevity
    }

    void addVariable(const std::string& namespaceName, const std::string& variableName, int value) {
        Namespace* targetNamespace = findNamespace(root, namespaceName);
        if (targetNamespace != nullptr) {
            targetNamespace->variables[variableName] = value;
        }
    }

    int getVariable(const std::string& namespaceName, const std::string& variableName) {
        Namespace* targetNamespace = findNamespace(root, namespaceName);
        if (targetNamespace != nullptr) {
            return getVariableValue(targetNamespace, variableName);
        }
        return -1; // Namespace not found
    }

    Namespace* getNamespace(const std::string& namespaceName) {
        return findNamespace(root, namespaceName);
    }
};

int main() {
    NamespaceManager manager;
    manager.createNamespace("global");
    manager.addVariable("global", "x", 10);
    manager.createNamespace("child1");
    manager.addVariable("child1", "y", 20);
    manager.createNamespace("child2");
    manager.addVariable("child2", "z", 30);
    manager.addVariable("global", "x", 100); // Overriding variable in the global namespace
    std::cout << manager.getVariable("child2", "x") << std::endl; // Should return 100 (inherited from the global namespace)
    std::cout << manager.getVariable("child1", "z") << std::endl; // Should return -1 (Variable not found)
    return 0;
}
