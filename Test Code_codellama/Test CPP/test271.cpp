#include <iostream>
#include <vector>
#include <map>

// Component class
class Component {
public:
    virtual ~Component() {}
    virtual void update() = 0;
};

// System class
class System {
public:
    virtual ~System() {}
    virtual void update() = 0;
};

// Components container
class Components {
public:
    Components() {}
    ~Components() {}

    void addComponent(Component* component) {
        components_.push_back(component);
    }

    void removeComponent(Component* component) {
        components_.erase(std::remove(components_.begin(), components_.end(), component), components_.end());
    }

    Component* getComponent(int index) {
        return components_[index];
    }

private:
    std::vector<Component*> components_;
};

// Systems container
class Systems {
public:
    Systems() {}
    ~Systems() {}

    void addSystem(System* system) {
        systems_.push_back(system);
    }

    void removeSystem(System* system) {
        systems_.erase(std::remove(systems_.begin(), systems_.end(), system), systems_.end());
    }

    System* getSystem(int index) {
        return systems_[index];
    }

private:
    std::vector<System*> systems_;
};

// Components and systems functions
Components& Components() {
    static Components components;
    return components;
}

Systems& Systems() {
    static Systems systems;
    return systems;
}

int main() {
    // Add a component
    Components().addComponent(new Component());

    // Add a system
    Systems().addSystem(new System());

    // Update components
    for (auto& component : Components()) {
        component->update();
    }

    // Update systems
    for (auto& system : Systems()) {
        system->update();
    }

    return 0;
}
