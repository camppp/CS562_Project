#include <iostream>
#include <cmath>

class Cylinder {
private:
    double x;
    double y;
    double radius;
    double height;

public:
    void setDimensions(double x, double y, double radius, double height) {
        this->x = x;
        this->y = y;
        this->radius = radius;
        this->height = height;
    }

    double area() const {
        return 3.14159 * radius * radius;
    }

    double volume() const {
        return 3.14159 * radius * radius * height;
    }
};

int main() {
    double x, y, radius, height;

    std::cout << "Enter the x-coordinate of the base center: ";
    std::cin >> x;
    std::cout << "Enter the y-coordinate of the base center: ";
    std::cin >> y;
    std::cout << "Enter the radius of the base: ";
    std::cin >> radius;
    std::cout << "Enter the height of the cylinder: ";
    std::cin >> height;

    Cylinder cylinder;
    cylinder.setDimensions(x, y, radius, height);

    std::cout << "The area of the base is: " << cylinder.area() << std::endl;
    std::cout << "The volume of the cylinder is: " << cylinder.volume() << std::endl;

    return 0;
}
