#include <cmath>

float calculateSphereVolume(float newRadius, float newOrigin[3]) {
    float volume = (4.0f / 3.0f) * M_PI * pow(newRadius, 3.0f);
    return volume;
}
