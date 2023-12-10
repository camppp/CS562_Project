#include <iostream>
#include <map>
#include <vector>
#include <string>

class Namespace {
public:
    Namespace(const std::string& name) : name_(name) {}

    void addVariable(const std::string& name, int value) {
        variables_[name] = value;
    }

    int getVariable(const std::string& name) {
        if (variables_.find(name) != variables_.end()) {
            return variables_[name];
        } else {
            return -1;
        }
    }

    std::string getName() {
        return name_;
    }

    void addChildNamespace(const std::string& name) {
        childNamespaces_.push_back(name);
    }

    std::vector<std::string> getChildNamespaces() {
        return childNamespaces_;
    }

private:
    std::string name_;
    std::map<std::string, int> variables_;
    std::vector<std::string> childNamespaces_;
};

class NamespaceManager {
public:
    NamespaceManager() {
        rootNamespace_ = std::make_shared<Namespace>("global");
    }

    void createNamespace(const std::string& name) {
        if (namespaces_.find(name) == namespaces_.end()) {
            namespaces_[name] = std::make_shared<Namespace>(name);
        }
    }

    void deleteNamespace(const std::string& name) {
        if (namespaces_.find(name) != namespaces_.end()) {
            namespaces_.erase(name);
        }
    }

    void addVariable(const std::string& namespaceName, const std::string& name, int value) {
        if (namespaces_.find(namespaceName) != namespaces_.end()) {
            namespaces_[namespaceName]->addVariable(name, value);
        }
    }

    int getVariable(const std::string& namespaceName, const std::string& name) {
        if (namespaces_.find(namespaceName) != namespaces_.end()) {
            return namespaces_[namespaceName]->getVariable(name);
        } else {
            return -1;
        }
    }

    std::shared_ptr<Namespace> getNamespace(const std::string& name) {
        if (namespaces_.find(name) != namespaces_.end()) {
            return namespaces_[name];
        } else {
            return nullptr;
        }
    }

private:
    std::map<std::string, std::shared_ptr<Namespace>> namespaces_;
    std::shared_ptr<Namespace> rootNamespace_;
};
