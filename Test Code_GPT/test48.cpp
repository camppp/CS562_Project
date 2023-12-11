#include <iostream>
#include <string>

// Interface definition
class SoftwareEntity {
public:
    virtual std::string HumanName() const = 0;
    virtual std::string InternalName() const = 0;
    virtual ~SoftwareEntity() = default; // Virtual destructor for polymorphic behavior
};

// Concrete class implementing the SoftwareEntity interface
class MySoftwareEntity : public SoftwareEntity {
public:
    MySoftwareEntity(const std::string& humanName, const std::string& internalName)
        : humanName_(humanName), internalName_(internalName) {}

    // Implementation of virtual functions
    std::string HumanName() const override {
        return humanName_;
    }

    std::string InternalName() const override {
        return internalName_;
    }

private:
    std::string humanName_;
    std::string internalName_;
};

int main() {
    // Create an instance of the concrete class
    MySoftwareEntity myEntity("My Software", "com.example.MySoftware");

    // Demonstrate the usage of virtual functions
    std::cout << "Human-Readable Name: " << myEntity.HumanName() << std::endl;
    std::cout << "Internal Name: " << myEntity.InternalName() << std::endl;

    return 0;
}
