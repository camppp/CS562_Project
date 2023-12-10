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
        return M_PI * radius * radius;
    }

    double volume() const {
        return M_PI * radius * radius * height;
    }
};

int main() {
    double x, y, radius, height;
    std::cout << "Enter the x-coordinate, y-coordinate, radius, and height of the cylinder: " << std::endl;
    std::cin >> x >> y >> radius >> height;

    Cylinder c1;
    c1.setDimensions(x, y, radius, height);

    std::cout << "Area of the base of the cylinder: " << c1.area() << std::endl;
    std::cout << "Volume of the cylinder: " << c1.volume() << std::endl;

    return 0;
}
