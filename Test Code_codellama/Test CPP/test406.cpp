#include "Mat3.h"

class ShapeSphere {
public:
    // ...
    Mat3 InertiaTensor() const {
        // Calculate the inertia tensor for the sphere
        float mass = 1.0f; // Replace with the actual mass of the sphere
        float radius = 1.0f; // Replace with the actual radius of the sphere
        float inertia = 2.0f / 5.0f * mass * radius * radius;

        // Create the inertia tensor matrix
        Mat3 inertiaTensor;
        inertiaTensor.Set(0, 0, inertia);
        inertiaTensor.Set(1, 1, inertia);
        inertiaTensor.Set(2, 2, inertia);

        return inertiaTensor;
    }
};
