#include <iostream>
#include <cmath>

class MaterialInfo {
public:
    // Constructor
    MaterialInfo() : mass(0.0f), restitution(0.0f), angular_damping(0.0f) {}

    // Setters for material properties
    void setMass(float newMass) {
        mass = newMass;
    }

    void setRestitution(float newRestitution) {
        restitution = newRestitution;
    }

    void setAngularDamping(float newAngularDamping) {
        angular_damping = newAngularDamping;
    }

    // Getter for mass
    float getMass() const {
        return mass;
    }

    // Getter for restitution
    float getRestitution() const {
        return restitution;
    }

    // Getter for angular damping
    float getAngularDamping() const {
        return angular_damping;
    }

    // Method to calculate kinetic energy
    float getKineticEnergy(float velocity) const {
        return 0.5f * mass * std::pow(velocity, 2);
    }

private:
    // Member variables
    float mass;
    float restitution;
    float angular_damping;
};

// Example usage
int main() {
    // Create MaterialInfo object
    MaterialInfo material;

    // Set material properties
    material.setMass(5.0f);
    material.setRestitution(0.8f);
    material.setAngularDamping(0.2f);

    // Display material properties
    std::cout << "Material Properties:" << std::endl;
    std::cout << "Mass: " << material.getMass() << " kg" << std::endl;
    std::cout << "Restitution: " << material.getRestitution() << std::endl;
    std::cout << "Angular Damping: " << material.getAngularDamping() << std::endl;

    // Calculate and display kinetic energy for an object with velocity
    float velocity = 10.0f;
    float kineticEnergy = material.getKineticEnergy(velocity);

    std::cout << "Kinetic Energy: " << kineticEnergy << " J" << std::endl;

    return 0;
}
