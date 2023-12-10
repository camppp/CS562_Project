#include <iostream>
#include <unordered_map>
#include <memory>
#include <string>

class Namespace {
private:
    std::unordered_map<std::string, std::string> variables;
    std::unordered_map<std::string, std::shared_ptr<Namespace>> subNamespaces;

public:
    void addVariable(const std::string& name, const std::string& value) {
        variables[name] = value;
    }

    std::string getVariableValue(const std::string& name) {
        if (variables.find(name) != variables.end()) {
            return variables[name];
        }
        return "Variable not found";
    }

    void createSubNamespace(const std::string& name) {
        subNamespaces[name] = std::make_shared<Namespace>();
    }

    std::shared_ptr<Namespace> getSubNamespace(const std::string& name) {
        if (subNamespaces.find(name) != subNamespaces.end()) {
            return subNamespaces[name];
        }
        return nullptr;
    }

    void deleteNamespace() {
        variables.clear();
        subNamespaces.clear();
    }
};

class NamespaceManager {
private:
    std::unordered_map<std::string, std::shared_ptr<Namespace>> namespaces;

public:
    void createNamespace(const std::string& name) {
        namespaces[name] = std::make_shared<Namespace>();
    }

    std::shared_ptr<Namespace> getNamespace(const std::string& name) {
        if (namespaces.find(name) != namespaces.end()) {
            return namespaces[name];
        }
        return nullptr;
    }

    void deleteNamespace(const std::string& name) {
        if (namespaces.find(name) != namespaces.end()) {
            namespaces[name]->deleteNamespace();
            namespaces.erase(name);
        }
    }
};

int main() {
    NamespaceManager manager;
    manager.createNamespace("Elastos");

    auto elastosNamespace = manager.getNamespace("Elastos");
    if (elastosNamespace) {
        elastosNamespace->addVariable("version", "1.0");
        elastosNamespace->createSubNamespace("Core");

        auto coreNamespace = elastosNamespace->getSubNamespace("Core");
        if (coreNamespace) {
            coreNamespace->addVariable("author", "Elastos Team");
        }
    }

    // Displaying the hierarchical structure
    std::cout << "Elastos namespace:" << std::endl;
    std::cout << "  version: " << elastosNamespace->getVariableValue("version") << std::endl;
    std::cout << "  Core namespace:" << std::endl;
    std::cout << "    author: " << elastosNamespace->getSubNamespace("Core")->getVariableValue("author") << std::endl;

    return 0;
}
