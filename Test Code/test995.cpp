#include <iostream>

class Rectangle {
private:
    double length;
    double width;

public:
    // Constructor
    Rectangle(double l, double w) {
        length = l;
        width = w;
    }

    // Complete member function to calculate area
    double calculateArea() {
        return length * width;
    }
};

int main() {
    Rectangle rect(5.0, 3.0);
    std::cout << "Area of the rectangle: " << rect.calculateArea() << std::endl;
    return 0;
}
