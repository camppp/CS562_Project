#include <iostream>

class Shape {
public:
    virtual double area() = 0;
    virtual double perimeter() = 0;
    virtual void displayDetails() = 0;
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double radius) : radius(radius) {}
    double area() { return 3.14 * radius * radius; }
    double perimeter() { return 2 * 3.14 * radius; }
    void displayDetails() {
        std::cout << "Circle with radius " << radius << " has area " << area() << " and perimeter " << perimeter() << std::endl;
    }
};

class Rectangle : public Shape {
private:
    double length, width;
public:
    Rectangle(double length, double width) : length(length), width(width) {}
    double area() { return length * width; }
    double perimeter() { return 2 * (length + width); }
    void displayDetails() {
        std::cout << "Rectangle with length " << length << " and width " << width << " has area " << area() << " and perimeter " << perimeter() << std::endl;
    }
};

class Triangle : public Shape {
private:
    double side1, side2, side3;
public:
    Triangle(double side1, double side2, double side3) : side1(side1), side2(side2), side3(side3) {}
    double area() { return (side1 + side2 + side3) / 2; }
    double perimeter() { return side1 + side2 + side3; }
    void displayDetails() {
        std::cout << "Triangle with sides " << side1 << ", " << side2 << ", and " << side3 << " has area " << area() << " and perimeter " << perimeter() << std::endl;
    }
};

int main() {
    Circle circle(5);
    Rectangle rectangle(10, 5);
    Triangle triangle(3, 4, 5);

    circle.displayDetails();
    rectangle.displayDetails();
    triangle.displayDetails();

    return 0;
}
