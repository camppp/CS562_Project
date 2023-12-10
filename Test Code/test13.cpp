#include <cmath>
#include <utility>

std::pair<float, float> vectorToOrientation(const McVec3f& orientation) {
    float phiRad = atan2(orientation[1], orientation[0]);
    float thetaRad = asin(orientation[2]);

    float phiDeg = phiRad * 180.0 / M_PI;
    float thetaDeg = thetaRad * 180.0 / M_PI;

    return std::make_pair(phiDeg, thetaDeg);
}
