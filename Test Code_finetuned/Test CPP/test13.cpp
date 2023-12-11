#include <cmath>
#include <utility>

// Define McVec3f as a simple 3D vector
struct McVec3f {
    float x, y, z;
    McVec3f(float x, float y, float z) : x(x), y(y), z(z) {}
};

std::pair<float, float> vectorToOrientation(const McVec3f& orientation) {
    float phiRad = atan2(orientation.y, orientation.x);
    float thetaRad = asin(orientation.z);

    float phiDeg = phiRad * 180.0 / M_PI;
    float thetaDeg = thetaRad * 180.0 / M_PI;

    return std::make_pair(phiDeg, thetaDeg);
}