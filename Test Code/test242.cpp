#include <cmath>

void CalculateSinCos(float angleInDegrees, float& sinValue, float& cosValue) {
    // Convert angle from degrees to radians
    float angleInRadians = angleInDegrees * M_PI / 180.0;

    // Calculate sine and cosine using standard mathematical functions
    sinValue = sin(angleInRadians);
    cosValue = cos(angleInRadians);
}
