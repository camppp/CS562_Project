#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class NamespaceManager {
public:
    void createNamespace(const std::string& name) {
        namespaces_.emplace(name, std::unordered_map<std::string, std::string>());
    }

    void addVariable(const std::string& namespaceName, const std::string& varName, const std::string& value) {
        auto& namespaceMap = namespaces_.at(namespaceName);
        namespaceMap.emplace(varName, value);
    }

    std::string getVariableValue(const std::string& namespaceName, const std::string& varName) {
        auto& namespaceMap = namespaces_.at(namespaceName);
        auto it = namespaceMap.find(varName);
        if (it == namespaceMap.end()) {
            throw std::runtime_error("Variable does not exist in namespace");
        }
        return it->second;
    }

    void createSubNamespace(const std::string& parentNamespace, const std::string& subNamespace) {
        auto& parentNamespaceMap = namespaces_.at(parentNamespace);
        parentNamespaceMap.emplace(subNamespace, std::unordered_map<std::string, std::string>());
    }

    void deleteNamespace(const std::string& namespaceName) {
        auto it = namespaces_.find(namespaceName);
        if (it == namespaces_.end()) {
            throw std::runtime_error("Namespace does not exist");
        }
        namespaces_.erase(it);
    }

private:
    std::unordered_map<std::string, std::unordered_map<std::string, std::string>> namespaces_;
};
