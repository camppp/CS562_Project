class MaterialInfo {
public:
    MaterialInfo() {}
    MaterialInfo(float mass, float restitution, float angular_damping) {
        setMass(mass);
        setRestitution(restitution);
        setAngularDamping(angular_damping);
    }

    void setMass(float mass) {
        this->mass = mass;
    }

    void setRestitution(float restitution) {
        this->restitution = restitution;
    }

    void setAngularDamping(float damping) {
        this->angular_damping = damping;
    }

    float getKineticEnergy(float velocity) {
        return 0.5 * mass * velocity * velocity;
    }

private:
    float mass;
    float restitution;
    float angular_damping;
};
