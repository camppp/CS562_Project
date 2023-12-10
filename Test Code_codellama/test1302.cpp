#include <iostream>
#include <string>
#include <unordered_map>

class NamespaceManager {
public:
    NamespaceManager() {}

    void createNamespace(const std::string& name) {
        namespaces_.emplace(name, std::make_unique<Namespace>(name));
    }

    void deleteNamespace(const std::string& name) {
        auto it = namespaces_.find(name);
        if (it != namespaces_.end()) {
            namespaces_.erase(it);
        }
    }

    Namespace* getNamespace(const std::string& name) {
        auto it = namespaces_.find(name);
        if (it != namespaces_.end()) {
            return it->second.get();
        }
        return nullptr;
    }

private:
    struct Namespace {
        std::string name;
        std::unordered_map<std::string, std::unique_ptr<Namespace>> contents;

        Namespace(const std::string& name) : name(name) {}
    };

    std::unordered_map<std::string, std::unique_ptr<Namespace>> namespaces_;
};
