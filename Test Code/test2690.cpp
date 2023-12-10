#include <iostream>

namespace datatools {

    class AbstractParticleManipulator {
    public:
        AbstractParticleManipulator(const std::string& outData, const std::string& inData) {
            // Constructor implementation
        }
        // Other member functions and variables
    };

    class ParticleColorSignedDistance : public AbstractParticleManipulator {
    private:
        Slot enableSlot;
        Slot cyclXSlot;

    public:
        ParticleColorSignedDistance(void)
                : AbstractParticleManipulator("outData", "indata"),
                  enableSlot("enable", "Enables the color manipulation"),
                  cyclXSlot("cyclX", "Considders cyclic boundary conditions in X direction") {
            // Constructor implementation
        }

        void enableColorManipulation() {
            // Implementation to enable color manipulation
            std::cout << "Color manipulation enabled" << std::endl;
        }

        void considerCyclicBoundaryConditionsX() {
            // Implementation to consider cyclic boundary conditions in X direction
            std::cout << "Cyclic boundary conditions in X considered" << std::endl;
        }

        void calculateSignedDistance() {
            // Implementation to calculate the signed distance of particles
            std::cout << "Signed distance calculated" << std::endl;
        }

        // Other member functions and variables
    };

}  // namespace datatools
