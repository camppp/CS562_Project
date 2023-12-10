#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>

// Function to calculate the area of a circle
double calculateCircleArea(double radius) {
    return M_PI * radius * radius;
}

int main() {
    double radius;
    std::cout << "Enter the radius of the circle: ";
    std::cin >> radius;

    double area = calculateCircleArea(radius);
    std::cout << "The area of the circle is: " << std::fixed << std::setprecision(2) << area << std::endl;

    return 0;
}
