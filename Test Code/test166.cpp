#include <math.h>

float calculateDistance(float x1, float y1, float x2, float y2) {
    float deltaX = x2 - x1;
    float deltaY = y2 - y1;
    float distance = sqrt(deltaX * deltaX + deltaY * deltaY);
    return distance;
}
