#include <iostream>
#include <unordered_map>
#include <memory>

namespace chrgfx {
    class Namespace {
        // Define the contents of the namespace
    };

    class NamespaceManager {
    private:
        std::unordered_map<std::string, std::unique_ptr<Namespace>> namespaces;

    public:
        void createNamespace(const std::string& name) {
            namespaces[name] = std::make_unique<Namespace>();
        }

        void deleteNamespace(const std::string& name) {
            namespaces.erase(name);
        }

        Namespace* getNamespace(const std::string& name) {
            auto it = namespaces.find(name);
            if (it != namespaces.end()) {
                return it->second.get();
            }
            return nullptr;
        }
    };
}
