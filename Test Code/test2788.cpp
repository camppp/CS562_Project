#include <cmath>

const float IMP_MIN_DIVISOR = 0.0001f; // Define a minimum divisor to avoid division by zero

float computeSphereThickness(const float invmat[16], const float position[3], float thicknessSquared) {
    const float tx = invmat[12] + position[0]; // Extract translation component along x-axis
    const float ty = invmat[13] + position[1]; // Extract translation component along y-axis
    const float tz = invmat[14] + position[2]; // Extract translation component along z-axis

    // Compute the thickness of the sphere at the given point using the provided formula
    return thicknessSquared / (tx * tx + ty * ty + tz * tz + IMP_MIN_DIVISOR);
}
