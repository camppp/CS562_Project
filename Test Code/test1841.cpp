#include <iostream>
#include <cmath>

// Function to calculate the distance between two points in a 2D plane
double calculateDistance(double x1, double y1, double x2, double y2) {
    return std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
}

int main() {
    // Test the calculateDistance function
    double x1 = 1.0, y1 = 2.0, x2 = 4.0, y2 = 6.0;
    std::cout << "Distance between (" << x1 << ", " << y1 << ") and (" << x2 << ", " << y2 << ") is: " << calculateDistance(x1, y1, x2, y2) << std::endl;
    return 0;
}
