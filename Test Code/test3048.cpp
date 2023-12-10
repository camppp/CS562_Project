#include <iostream>
#include <cmath>

// Function to calculate the volume of a sphere
float calculateSphereVolume(float radius) {
    const float pi = 3.14159;
    return (4.0 / 3.0) * pi * pow(radius, 3);
}

int main() {
    // Given initial origin and radius
    float origin[3] = {5., 0., 0.};
    float radius = 7.3;

    // Apply transformation to change the x-coordinate of the origin
    origin[0] = -5.0;

    // Calculate the volume of the sphere after the transformation
    float newRadius = radius;  // Assuming the radius remains unchanged after the transformation
    float volume = calculateSphereVolume(newRadius);

    // Output the volume of the sphere after the transformation
    std::cout << "Volume of the sphere after transformation: " << volume << std::endl;

    return 0;
}
