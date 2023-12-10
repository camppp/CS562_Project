#include <iostream>
#include <cmath>

double calculateTriangleArea(int x1, int y1, int x2, int y2, int x3, int y3) {
    return std::abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}

int main() {
    int x1, y1, x2, y2, x3, y3;
    std::cout << "Enter the coordinates of the first point (x1 y1): ";
    std::cin >> x1 >> y1;
    std::cout << "Enter the coordinates of the second point (x2 y2): ";
    std::cin >> x2 >> y2;
    std::cout << "Enter the coordinates of the third point (x3 y3): ";
    std::cin >> x3 >> y3;

    double area = calculateTriangleArea(x1, y1, x2, y2, x3, y3);
    std::cout << "The area of the triangle formed by the given points is: " << area << std::endl;

    return 0;
}
