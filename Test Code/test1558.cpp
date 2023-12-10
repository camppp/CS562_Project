#include <vector>
#include <unordered_map>
#include <queue>

std::vector<ModuleId> resolveInitializationOrder(const std::vector<Module>& modules) {
    std::unordered_map<ModuleId, std::vector<ModuleId>> dependencyMap;
    std::unordered_map<ModuleId, int> dependencyCount;

    for (const auto& module : modules) {
        dependencyMap[module.id] = module.dependencies;
        dependencyCount[module.id] = module.dependencies.size();
    }

    std::vector<ModuleId> initializationOrder;
    std::queue<ModuleId> moduleQueue;

    for (const auto& module : modules) {
        if (module.dependencies.empty()) {
            moduleQueue.push(module.id);
            initializationOrder.push_back(module.id);
        }
    }

    while (!moduleQueue.empty()) {
        ModuleId currentModule = moduleQueue.front();
        moduleQueue.pop();

        for (const auto& [moduleId, dependencies] : dependencyMap) {
            for (const auto& dependency : dependencies) {
                if (dependency == currentModule) {
                    dependencyCount[moduleId]--;
                    if (dependencyCount[moduleId] == 0) {
                        moduleQueue.push(moduleId);
                        initializationOrder.push_back(moduleId);
                    }
                }
            }
        }
    }

    return initializationOrder;
}
