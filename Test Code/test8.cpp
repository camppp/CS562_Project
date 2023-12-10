#include <iostream>
#include <cmath>

class MaterialInfo {
private:
    float mass;
    float restitution;
    float angular_damping;

public:
    void setMass(float mass) {
        this->mass = mass;
    }

    void setRestitution(float restitution) {
        this->restitution = restitution;
    }

    void setAngularDamping(float damping) {
        angular_damping = damping;
    }

    float getKineticEnergy(float velocity) {
        return 0.5f * mass * pow(velocity, 2);
    }
};

int main() {
    MaterialInfo info;
    info.setMass(10.0f);
    info.setRestitution(0.05f);
    info.setAngularDamping(0.3f);

    float velocity = 5.0f;
    float kineticEnergy = info.getKineticEnergy(velocity);

    std::cout << "Material Properties:" << std::endl;
    std::cout << "Mass: " << info.mass << std::endl;
    std::cout << "Restitution: " << info.restitution << std::endl;
    std::cout << "Angular Damping: " << info.angular_damping << std::endl;
    std::cout << "Kinetic Energy at velocity " << velocity << ": " << kineticEnergy << std::endl;

    return 0;
}
