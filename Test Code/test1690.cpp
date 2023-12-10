#include <iostream>
#include <cmath>

class Point {
private:
    double x, y, radius, angle;

public:
    // Constructor for Cartesian coordinates
    Point(double x, double y) : x(x), y(y) {
        radius = sqrt(x * x + y * y);
        angle = atan2(y, x);
    }

    // Constructor for polar coordinates
    Point(double radius, double angle, bool isPolar) : radius(radius), angle(angle) {
        x = radius * cos(angle);
        y = radius * sin(angle);
    }

    // Method to convert from Cartesian to polar coordinates
    void toPolar() {
        radius = sqrt(x * x + y * y);
        angle = atan2(y, x);
    }

    // Method to convert from polar to Cartesian coordinates
    void toCartesian() {
        x = radius * cos(angle);
        y = radius * sin(angle);
    }

    // Method to retrieve x coordinate
    double getX() {
        return x;
    }

    // Method to retrieve y coordinate
    double getY() {
        return y;
    }

    // Method to retrieve radius
    double getRadius() {
        return radius;
    }

    // Method to retrieve angle
    double getAngle() {
        return angle;
    }
};

int main() {
    // Test the Point class
    Point cartesianPoint(3, 4);
    std::cout << "Cartesian Point: (" << cartesianPoint.getX() << ", " << cartesianPoint.getY() << ")" << std::endl;

    cartesianPoint.toPolar();
    std::cout << "Polar Point: (r=" << cartesianPoint.getRadius() << ", θ=" << cartesianPoint.getAngle() << ")" << std::endl;

    Point polarPoint(5, 0.9273, true);
    std::cout << "Polar Point: (r=" << polarPoint.getRadius() << ", θ=" << polarPoint.getAngle() << ")" << std::endl;

    polarPoint.toCartesian();
    std::cout << "Cartesian Point: (" << polarPoint.getX() << ", " << polarPoint.getY() << ")" << std::endl;

    return 0;
}
