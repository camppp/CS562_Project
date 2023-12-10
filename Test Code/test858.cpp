#include <iostream>

class Rectangle {
private:
    int width;
    int height;

public:
    Rectangle(int width, int height) : width(width), height(height) {}

    int area() {
        return width * height;
    }

    int perimeter() {
        return 2 * (width + height);
    }
};

int main() {
    Rectangle rect(5, 3);
    std::cout << "Area: " << rect.area() << std::endl;
    std::cout << "Perimeter: " << rect.perimeter() << std::endl;
    return 0;
}
