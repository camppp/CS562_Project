#include <unordered_map>
#include <vector>

// GUID structure
struct mxGUID {
    uint64_t data1;
    uint64_t data2;
    uint64_t data3;
    uint64_t data4;
};

// DependencyManager class
class DependencyManager {
public:
    // Register a new module with its dependencies
    void RegisterModule(const std::string& moduleName, const std::vector<mxGUID>& dependencies) {
        // Check if the module is already registered
        if (moduleNameToDependencies.find(moduleName) != moduleNameToDependencies.end()) {
            throw std::runtime_error("Module already registered");
        }

        // Add the module and its dependencies to the map
        moduleNameToDependencies[moduleName] = dependencies;
    }

    // Retrieve the dependencies of a given module
    std::vector<mxGUID> GetDependencies(const std::string& moduleName) {
        // Check if the module is registered
        if (moduleNameToDependencies.find(moduleName) == moduleNameToDependencies.end()) {
            throw std::runtime_error("Module not registered");
        }

        // Return the dependencies of the module
        return moduleNameToDependencies[moduleName];
    }

private:
    // Map of module names to their dependencies
    std::unordered_map<std::string, std::vector<mxGUID>> moduleNameToDependencies;
};
