#include <iostream>
#include <vector>

class AbstractParticleManipulator {
public:
    virtual void enableColorManipulation() = 0;
    virtual void considerCyclicBoundaryConditionsX() = 0;
    virtual void calculateSignedDistance() = 0;
};

class ParticleColorSignedDistance : public AbstractParticleManipulator {
public:
    ParticleColorSignedDistance(bool enableSlot, bool cyclXSlot) : enableSlot(enableSlot), cyclXSlot(cyclXSlot) {}

    void enableColorManipulation() override {
        // Implement color manipulation logic here
    }

    void considerCyclicBoundaryConditionsX() override {
        // Implement cyclic boundary conditions logic here
    }

    void calculateSignedDistance() override {
        // Implement signed distance calculation logic here
    }

private:
    bool enableSlot;
    bool cyclXSlot;
};
