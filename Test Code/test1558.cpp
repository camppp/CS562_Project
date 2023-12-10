std::vector<ModuleId> resolveInitializationOrder(const std::vector<Module>& modules) {
    // Create a map of module IDs to their dependencies
    std::map<ModuleId, std::vector<ModuleId>> dependencies;
    for (const auto& module : modules) {
        dependencies[module.id] = module.dependencies;
    }

    // Create a set of module IDs that have no dependencies
    std::set<ModuleId> noDependencies;
    for (const auto& module : modules) {
        if (dependencies[module.id].empty()) {
            noDependencies.insert(module.id);
        }
    }

    // Initialize the list of modules to be initialized
    std::vector<ModuleId> modulesToInitialize;

    // Iterate over the modules in the order they should be initialized
    while (!noDependencies.empty()) {
        // Get the next module to initialize
        ModuleId nextModuleId = *noDependencies.begin();
        noDependencies.erase(nextModuleId);

        // Add the next module to the list of modules to be initialized
        modulesToInitialize.push_back(nextModuleId);

        // Remove the next module's dependencies from the set of no dependencies
        for (const auto& dependency : dependencies[nextModuleId]) {
            noDependencies.erase(dependency);
        }
    }

    return modulesToInitialize;
}
