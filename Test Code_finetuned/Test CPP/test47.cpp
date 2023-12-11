#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <stack>

class DependencyResolver {
public:
    void registerDependency(const std::string& dependent, const std::string& dependency) {
        dependencies_[dependent].push_back(dependency);
    }

    void resolveDependencies(const std::string& component) {
        if (resolved_.find(component)!= resolved_.end()) {
            return;
        }

        if (visiting_.find(component)!= visiting_.end()) {
            throw std::runtime_error("Circular dependency detected");
        }

        visiting_.insert(component);

        for (const auto& dependency : dependencies_[component]) {
            resolveDependencies(dependency);
        }

        resolved_.insert(component);
        visiting_.erase(component);
    }

private:
    std::map<std::string, std::vector<std::string>> dependencies_;
    std::set<std::string> resolved_;
    std::set<std::string> visiting_;
};

int main() {
    DependencyResolver resolver;

    resolver.registerDependency("System1", "Entity1");
    resolver.registerDependency("Entity1", "Component1");
    resolver.registerDependency("Entity1", "Component2");
    resolver.registerDependency("System2", "Entity1");
    resolver.registerDependency("System2", "Entity2");
    resolver.registerDependency("Entity2", "Component3");

    try {
        resolver.resolveDependencies("System1");
        resolver.resolveDependencies("System2");
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}