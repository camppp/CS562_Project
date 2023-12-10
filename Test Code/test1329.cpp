// cone.hpp
#ifndef CONE_HPP
#define CONE_HPP

#include "shape.hpp"

class Cone : public Shape {
private:
    double radius;
    double height;

public:
    Cone(double r, double h) : radius(r), height(h) {}

    double calculateVolume() {
        return (1.0 / 3.0) * PI * radius * radius * height;
    }

    double calculateSurfaceArea() {
        return PI * radius * (radius + sqrt(radius * radius + height * height));
    }
};

#endif

// cylinder.hpp
#ifndef CYLINDER_HPP
#define CYLINDER_HPP

#include "shape.hpp"

class Cylinder : public Shape {
private:
    double radius;
    double height;

public:
    Cylinder(double r, double h) : radius(r), height(h) {}

    double calculateVolume() {
        return PI * radius * radius * height;
    }

    double calculateSurfaceArea() {
        return 2 * PI * radius * (radius + height);
    }
};

#endif

// ucylinder.hpp
#ifndef UCYLINDER_HPP
#define UCYLINDER_HPP

#include "cylinder.hpp"

class UCylinder : public Cylinder {
private:
    double innerRadius;

public:
    UCylinder(double r, double h, double ir) : Cylinder(r, h), innerRadius(ir) {}

    double calculateVolume() {
        return Cylinder::calculateVolume() - (PI * innerRadius * innerRadius * height);
    }

    double calculateSurfaceArea() {
        return Cylinder::calculateSurfaceArea() - (2 * PI * innerRadius * height);
    }
};

#endif

// paraboloid.hpp
#ifndef PARABOLOID_HPP
#define PARABOLOID_HPP

#include "shape.hpp"

class Paraboloid : public Shape {
private:
    double radius;
    double height;

public:
    Paraboloid(double r, double h) : radius(r), height(h) {}

    double calculateVolume() {
        return (1.0 / 2.0) * PI * radius * radius * height;
    }

    double calculateSurfaceArea() {
        return PI * radius * sqrt(radius * radius + height * height);
    }
};

#endif

// main.cpp
#include <iostream>
#include "cone.hpp"
#include "cylinder.hpp"
#include "ucylinder.hpp"
#include "paraboloid.hpp"

int main() {
    Cone cone(3.0, 4.0);
    Cylinder cylinder(2.0, 5.0);
    UCylinder ucylinder(4.0, 6.0, 3.0);
    Paraboloid paraboloid(2.0, 3.0);

    std::cout << "Cone - Volume: " << cone.calculateVolume() << ", Surface Area: " << cone.calculateSurfaceArea() << std::endl;
    std::cout << "Cylinder - Volume: " << cylinder.calculateVolume() << ", Surface Area: " << cylinder.calculateSurfaceArea() << std::endl;
    std::cout << "UCylinder - Volume: " << ucylinder.calculateVolume() << ", Surface Area: " << ucylinder.calculateSurfaceArea() << std::endl;
    std::cout << "Paraboloid - Volume: " << paraboloid.calculateVolume() << ", Surface Area: " << paraboloid.calculateSurfaceArea() << std::endl;

    return 0;
}
