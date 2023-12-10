#include <cmath>
#include <iostream>

// Assuming the McVec3f class is defined with appropriate functionality
class McVec3f {
public:
    McVec3f(float x, float y, float z) : x(x), y(y), z(z) {}
    // Add any other necessary functionality if McVec3f is not provided

    float getX() const { return x; }
    float getY() const { return y; }
    float getZ() const { return z; }

private:
    float x, y, z;
};

std::pair<float, float> vectorToOrientation(const McVec3f& orientation) {
    // Calculate theta (θ) in radians
    float thetaRad = std::asin(orientation.getZ());

    // Calculate phi (φ) in radians
    float phiRad = std::atan2(orientation.getY(), orientation.getX());

    // Convert radians to degrees
    float thetaDeg = (thetaRad / M_PI) * 180.0;
    float phiDeg = (phiRad / M_PI) * 180.0;

    return std::make_pair(phiDeg, thetaDeg);
}

int main() {
    // Example usage
    McVec3f orientationVector(0.5, 0.5, 0.707);
    std::pair<float, float> angles = vectorToOrientation(orientationVector);

    std::cout << "Phi (φ): " << angles.first << " degrees" << std::endl;
    std::cout << "Theta (θ): " << angles.second << " degrees" << std::endl;

    return 0;
}
