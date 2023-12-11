#include <iostream>
#include <string>

// Interface
class IEntity {
public:
    virtual std::string HumanName() const = 0;
    virtual std::string InternalName() const = 0;
};

// Concrete class
class Entity : public IEntity {
public:
    std::string HumanName() const override {
        return "Entity";
    }

    std::string InternalName() const override {
        return "namespace::Entity";
    }
};

int main() {
    // Create an instance of the concrete class
    Entity entity;

    // Invoke the virtual functions
    std::cout << "Human-readable name: " << entity.HumanName() << std::endl;
    std::cout << "Fully namespace-qualified name: " << entity.InternalName() << std::endl;

    return 0;
}