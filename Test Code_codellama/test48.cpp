#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>

// Forward declarations
class Component;
class Entity;
class System;

// Dependency resolution system
class DependencyResolver {
public:
    // Register a component
    void registerComponent(const std::string& name, Component* component) {
        components[name] = component;
    }

    // Register an entity
    void registerEntity(const std::string& name, Entity* entity) {
        entities[name] = entity;
    }

    // Register a system
    void registerSystem(const std::string& name, System* system) {
        systems[name] = system;
    }

    // Resolve dependencies
    void resolveDependencies() {
        // Iterate over all components
        for (auto& component : components) {
            // Check if the component has any dependencies
            if (component.second->getDependencies().size() > 0) {
                // Iterate over all dependencies
                for (auto& dependency : component.second->getDependencies()) {
                    // Check if the dependency is a component
                    if (components.find(dependency) != components.end()) {
                        // Add the dependency to the component's dependencies
                        component.second->addDependency(dependency);
                    } else if (entities.find(dependency) != entities.end()) {
                        // Add the dependency to the component's dependencies
                        component.second->addDependency(dependency);
                    } else if (systems.find(dependency) != systems.end()) {
                        // Add the dependency to the component's dependencies
                        component.second->addDependency(dependency);
                    } else {
                        // Dependency not found, throw an error
                        throw std::runtime_error("Dependency not found: " + dependency);
                    }
                }
            }
        }

        // Iterate over all entities
        for (auto& entity : entities) {
            // Check if the entity has any dependencies
            if (entity.second->getDependencies().size() > 0) {
                // Iterate over all dependencies
                for (auto& dependency : entity.second->getDependencies()) {
                    // Check if the dependency is a component
                    if (components.find(dependency) != components.end()) {
                        // Add the dependency to the entity's dependencies
                        entity.second->addDependency(dependency);
                    } else if (entities.find(dependency) != entities.end()) {
                        // Add the dependency to the entity's dependencies
                        entity.second->addDependency(dependency);
                    } else if (systems.find(dependency) != systems.end()) {
                        // Add the dependency to the entity's dependencies
                        entity.second->addDependency(dependency);
                    } else {
                        // Dependency not found, throw an error
                        throw std::runtime_error("Dependency not found: " + dependency);
                    }
                }
            }
        }

        // Iterate over all systems
        for (auto& system : systems) {
            // Check if the system has any dependencies
            if (system.second->getDependencies().size() > 0) {
                // Iterate over all dependencies
                for (auto& dependency : system.second->getDependencies()) {
                    // Check if the dependency is a component
                    if (components.find(dependency) != components.end()) {
                        // Add the dependency to the system's dependencies
                        system.second->addDependency(dependency);
                    } else if (entities.find(dependency) != entities.end()) {
                        // Add the dependency to the system's dependencies
                        system.second->addDependency(dependency);
                    } else if (systems.find(dependency) != systems.end()) {
                        // Add the dependency to the system's dependencies
                        system.second->addDependency(dependency);
                    } else {
                        // Dependency not found, throw an error
                        throw std::runtime_error("Dependency not found: " + dependency);
                    }
                }
            }
        }
    }

private:
    // Map of components by name
    std::unordered_map<std::string, Component*> components;

    // Map of entities by name
    std::unordered_map<std::string, Entity*> entities;

    // Map of systems by name
    std::unordered_map<std::string, System*> systems;
};

// Component class
class Component {
public:
    // Constructor
    Component(const std::string& name) : name(name) {}

    // Get the component's name
    const std::string& getName() const {
        return name;
    }

    // Get the component's dependencies
    const std::vector<std::string>& getDependencies() const {
        return dependencies;
    }

    // Add a dependency to the component
    void addDependency(const std::string& dependency) {
        dependencies.push_back(dependency);
    }

private:
    // Component name
    std::string name;

    // Component dependencies
    std::vector<std::string> dependencies;
};

// Entity class
class Entity {
public:
    // Constructor
    Entity(const std::string& name) : name(name) {}

    // Get the entity's name
    const std::string& getName() const {
        return name;
    }

    // Get the entity's dependencies
    const std::vector<std::string>& getDependencies() const {
        return dependencies;
    }

    // Add a dependency to the entity
    void addDependency(const std::string& dependency) {
        dependencies.push_back(dependency);
    }

private:
    // Entity name
    std::string name;

    // Entity dependencies
    std::vector<std::string> dependencies;
};

// System class
class System {
public:
    // Constructor
    System(const std::string& name) : name(name) {}

    // Get the system's name
    const std::string& getName() const {
        return name;
    }

    // Get the system's dependencies
    const std::vector<std::string>& getDependencies() const {
        return dependencies;
    }

    // Add a dependency to the system
    void addDependency(const std::string& dependency) {
        dependencies.push_back(dependency);
    }

private:
    // System name
    std::string name;

    // System dependencies
    std::vector<std::string> dependencies;
};
