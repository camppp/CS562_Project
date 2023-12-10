#include <iostream>
#include <cmath>

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
    Circle(double r) : radius(r) {}

    double area() override {
        return M_PI * radius * radius;
    }

    double perimeter() override {
        return 2 * M_PI * radius;
    }

    void displayDetails() override {
        std::cout << "Circle - Radius: " << radius << ", Area: " << area() << ", Perimeter: " << perimeter() << std::endl;
    }
};

class Rectangle : public Shape {
private:
    double length, width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double area() override {
        return length * width;
    }

    double perimeter() override {
        return 2 * (length + width);
    }

    void displayDetails() override {
        std::cout << "Rectangle - Length: " << length << ", Width: " << width << ", Area: " << area() << ", Perimeter: " << perimeter() << std::endl;
    }
};

class Triangle : public Shape {
private:
    double side1, side2, side3;

public:
    Triangle(double s1, double s2, double s3) : side1(s1), side2(s2), side3(s3) {}

    double area() override {
        double s = (side1 + side2 + side3) / 2;
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }

    double perimeter() override {
        return side1 + side2 + side3;
    }

    void displayDetails() override {
        std::cout << "Triangle - Side1: " << side1 << ", Side2: " << side2 << ", Side3: " << side3 << ", Area: " << area() << ", Perimeter: " << perimeter() << std::endl;
    }
};

int main() {
    Circle c(5);
    Rectangle r(4, 6);
    Triangle t(3, 4, 5);

    c.displayDetails();
    r.displayDetails();
    t.displayDetails();

    return 0;
}
