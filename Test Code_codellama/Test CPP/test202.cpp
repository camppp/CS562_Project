#include <iostream>

class Rectangle {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double getArea() {
        return width * height;
    }

    double getPerimeter() {
        return 2 * (width + height);
    }
};

int main() {
    Rectangle rect(5.0, 3.0);
    std::cout << "Area: " << rect.getArea() << std::endl; // Output: Area: 15.0
    std::cout << "Perimeter: " << rect.getPerimeter() << std::endl; // Output: Perimeter: 16.0
    return 0;
}
