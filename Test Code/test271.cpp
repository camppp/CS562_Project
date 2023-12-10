#include <iostream>
#include <unordered_map>
#include <string>

// Forward declarations
class Component;
class System;

// Entity class to hold components and systems
class Entity {
public:
    std::unordered_map<std::string, Component*> components;
    std::unordered_map<std::string, System*> systems;

    void addComponent(const std::string& name, Component* component) {
        components[name] = component;
    }

    void removeComponent(const std::string& name) {
        components.erase(name);
    }

    Component* getComponent(const std::string& name) {
        return components[name];
    }

    void addSystem(const std::string& name, System* system) {
        systems[name] = system;
    }

    void removeSystem(const std::string& name) {
        systems.erase(name);
    }

    System* getSystem(const std::string& name) {
        return systems[name];
    }
};

// Component class
class Component {
public:
    // Add member variables and methods as needed
};

// System class
class System {
public:
    // Add member variables and methods as needed
};

// Function to return reference to components
Entity& Components() {
    static Entity entity;
    return entity;
}

// Function to return reference to systems
Entity& Systems() {
    static Entity entity;
    return entity;
}

int main() {
    // Usage example
    Entity& entity = Components();
    Component* component = new Component();
    entity.addComponent("exampleComponent", component);

    Entity& systemEntity = Systems();
    System* system = new System();
    systemEntity.addSystem("exampleSystem", system);

    return 0;
}
