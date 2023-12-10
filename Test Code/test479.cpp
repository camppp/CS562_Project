#include <iostream>

class GeometricShape {
protected:
    double area;

public:
    virtual void calculateArea() = 0;
};

class Circle : public GeometricShape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    void calculateArea() override {
        area = 3.14159 * radius * radius;
    }
};

class Rectangle : public GeometricShape {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    void calculateArea() override {
        area = length * width;
    }
};

int main() {
    Circle circle(5.0);
    circle.calculateArea();
    std::cout << "Area of circle: " << circle.area << std::endl;

    Rectangle rectangle(4.0, 6.0);
    rectangle.calculateArea();
    std::cout << "Area of rectangle: " << rectangle.area << std::endl;

    return 0;
}
