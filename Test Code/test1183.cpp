#include <iostream>
#include <cmath>

double calculateTriangleArea(double x1, double y1, double x2, double y2, double x3, double y3) {
    return 0.5 * std::abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
}

int main() {
    // Example usage
    double x1 = 0.0, y1 = 0.0;
    double x2 = 3.0, y2 = 0.0;
    double x3 = 0.0, y3 = 4.0;

    double area = calculateTriangleArea(x1, y1, x2, y2, x3, y3);
    std::cout << "Area of the triangle: " << area << std::endl;

    return 0;
}
