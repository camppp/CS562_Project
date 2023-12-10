#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

class NamespaceManager {
private:
    struct Variable {
        std::string name;
        int value;
    };

    std::unordered_map<std::string, std::vector<Variable>> namespaces;

public:
    void addNamespace(const std::string& namespaceName) {
        namespaces[namespaceName];
    }

    void removeNamespace(const std::string& namespaceName) {
        namespaces.erase(namespaceName);
    }

    void addVariable(const std::string& namespaceName, const std::string& variableName, int value) {
        namespaces[namespaceName].push_back({variableName, value});
    }

    int getVariableValue(const std::string& fullyQualifiedName) {
        size_t pos = fullyQualifiedName.find_last_of('.');
        std::string namespaceName = fullyQualifiedName.substr(0, pos);
        std::string variableName = fullyQualifiedName.substr(pos + 1);

        if (namespaces.find(namespaceName) != namespaces.end()) {
            for (const auto& variable : namespaces[namespaceName]) {
                if (variable.name == variableName) {
                    return variable.value;
                }
            }
        }
        return -1; // Variable not found
    }
};

int main() {
    NamespaceManager nsManager;
    nsManager.addNamespace("Prova");
    nsManager.addVariable("Prova", "var1", 10);
    nsManager.addNamespace("Prova.Inner");
    nsManager.addVariable("Prova.Inner", "var2", 20);
    std::cout << nsManager.getVariableValue("Prova.var1") << std::endl; // Output: 10
    return 0;
}
