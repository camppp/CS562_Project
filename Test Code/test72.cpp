#include <iostream>
#include <string>

// Define the interface for the software entity
class SoftwareEntity {
public:
    // Pure virtual function to return the human-readable name
    virtual std::string HumanName() const = 0;

    // Pure virtual function to return the fully namespace-qualified name of the instance class
    virtual std::string InternalName() const = 0;
};

// Concrete class implementing the SoftwareEntity interface
class ConcreteEntity : public SoftwareEntity {
public:
    std::string HumanName() const override {
        return "Concrete Entity";
    }

    std::string InternalName() const override {
        return "namespace::ConcreteEntity";
    }
};

int main() {
    // Create an instance of the ConcreteEntity class
    ConcreteEntity concreteEntity;

    // Invoke the virtual functions to display the human-readable name and the fully namespace-qualified name
    std::cout << "Human-readable name: " << concreteEntity.HumanName() << std::endl;
    std::cout << "Fully namespace-qualified name: " << concreteEntity.InternalName() << std::endl;

    return 0;
}
