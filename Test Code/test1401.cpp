#include <iostream>

class Cylinder {
public:
    // Default constructor with default parameters
    Cylinder(int levels = 16) : radius_(1.0f), height_(1.0f), levels_(levels) {}

    // Constructor with explicit parameters
    Cylinder(float radius, float height, int levels = 16) : radius_(radius), height_(height), levels_(levels) {}

    // Other methods and members can be added as needed

private:
    float radius_;  // Radius of the cylinder
    float height_;  // Height of the cylinder
    int levels_;    // Granularity of the mesh
};

int main() {
    // Create a cylinder using the default constructor
    Cylinder defaultCylinder;
    std::cout << "Default Cylinder - Radius: " << defaultCylinder.radius_ << ", Height: " << defaultCylinder.height_ << ", Levels: " << defaultCylinder.levels_ << std::endl;

    // Create a cylinder using the explicit constructor
    Cylinder customCylinder(2.5f, 5.0f, 32);
    std::cout << "Custom Cylinder - Radius: " << customCylinder.radius_ << ", Height: " << customCylinder.height_ << ", Levels: " << customCylinder.levels_ << std::endl;

    return 0;
}
