#include <stdint.h>

typedef float float32;

#define PI 3.14159265358979323846f

inline float32 cosf32(const float32 value)
{
    // Reduce the angle to the range [-π, π]
    float32 angle = value;
    while (angle > PI) {
        angle -= 2 * PI;
    }
    while (angle < -PI) {
        angle += 2 * PI;
    }

    // Calculate the cosine using Taylor series approximation
    float32 result = 1.0f;
    float32 term = 1.0f;
    float32 angleSquared = angle * angle;
    int32_t sign = -1;
    for (int32_t i = 2; i <= 10; i += 2) {
        term *= angleSquared / (i * (i - 1));
        result += sign * term;
        sign = -sign;
    }

    return result;
}

inline float32 tanf32(const float32 value)
{
    // Reduce the angle to the range [-π, π]
    float32 angle = value;
    while (angle > PI) {
        angle -= 2 * PI;
    }
    while (angle < -PI) {
        angle += 2 * PI;
    }

    // Calculate the tangent using the sine and cosine functions
    float32 sine = angle - (angle * angle * angle) / 6.0f;
    float32 cosine = 1.0f - (angle * angle) / 2.0f;
    return sine / cosine;
}
