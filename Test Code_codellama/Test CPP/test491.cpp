#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>

double calculateCircleArea(double radius) {
    return 3.14 * radius * radius;
}

int main() {
    double radius;
    std::cout << "Enter the radius of the circle: ";
    std::cin >> radius;

    double area = calculateCircleArea(radius);
    std::cout << "The area of the circle is: " << std::fixed << std::setprecision(2) << area << std::endl;

    return 0;
}
