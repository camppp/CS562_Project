#include <iostream>

class Rectangle {
private:
    double length;
    double width;

public:
    void setLength(double l) {
        length = l;
    }

    void setWidth(double w) {
        width = w;
    }

    double calculateArea() {
        return length * width;
    }

    double calculatePerimeter() {
        return 2 * (length + width);
    }
};

int main() {
    Rectangle rect;
    rect.setLength(5.0);
    rect.setWidth(3.0);

    std::cout << "Area of the rectangle: " << rect.calculateArea() << std::endl;
    std::cout << "Perimeter of the rectangle: " << rect.calculatePerimeter() << std::endl;

    return 0;
}
