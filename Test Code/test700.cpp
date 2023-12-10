#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

// Resource class to represent different types of resources
class Resource {
public:
    std::string name;
    Resource(const std::string& n) : name(n) {}
};

// Initializer class to specify the resources used and built during initialization
class Initializer {
protected:
    std::vector<std::string> usesResources;
    std::vector<std::string> buildsResources;

public:
    Initializer(const std::string& name) {
        std::cout << "Initializing " << name << std::endl;
    }

    void usesResource(const std::string& resource) {
        usesResources.push_back(resource);
    }

    void buildsResource(const std::string& resource) {
        buildsResources.push_back(resource);
    }
};

// Resource Manager to track the usage and building of resources during initialization
class ResourceManager {
private:
    std::unordered_map<std::string, Resource> resources;

public:
    void addResource(const std::string& name) {
        resources.emplace(name, Resource(name));
    }

    bool hasResource(const std::string& name) {
        return resources.find(name) != resources.end();
    }

    void printResources() {
        std::cout << "Available Resources:" << std::endl;
        for (const auto& pair : resources) {
            std::cout << pair.first << std::endl;
        }
    }
};

int main() {
    // Example usage
    ResourceManager manager;
    manager.addResource("em");
    manager.addResource("procgen");
    manager.addResource("engtypes");

    init_procgen::init_procgen initializer;
    initializer.usesResource("em");
    initializer.buildsResource("procgen");
    initializer.buildsResource("engtypes");

    manager.printResources();

    return 0;
}
