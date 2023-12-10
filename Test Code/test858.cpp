#include <iostream>

class Rectangle {
private:
    int width;
    int height;

public:
    Rectangle(int width, int height) {
        this->width = width;
        this->height = height;
    }

    int area() {
        return width * height;
    }

    int perimeter() {
        return 2 * (width + height);
    }
};

int main() {
    Rectangle r(5, 3);
    std::cout << "Area: " << r.area() << std::endl;
    std::cout << "Perimeter: " << r.perimeter() << std::endl;
    return 0;
}
