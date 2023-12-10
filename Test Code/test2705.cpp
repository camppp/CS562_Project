#include <iostream>
#include <cmath>
#include <utility>

float distanceSquared(std::pair<float, float> point1, std::pair<float, float> point2) {
    float x1 = point1.first;
    float y1 = point1.second;
    float x2 = point2.first;
    float y2 = point2.second;

    float squared_distance = std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2);
    return squared_distance;
}

int main() {
    // Test the distanceSquared function
    std::pair<float, float> point1 = std::make_pair(1.0f, 2.0f);
    std::pair<float, float> point2 = std::make_pair(3.0f, 4.0f);
    float result = distanceSquared(point1, point2);
    std::cout << "Squared distance between points: " << result << std::endl;

    return 0;
}
