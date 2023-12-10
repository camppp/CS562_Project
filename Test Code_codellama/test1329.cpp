#ifndef CONE_HPP
#define CONE_HPP

#include "shape.hpp"

class Cone : public Shape {
public:
    Cone(double radius, double height) : Shape(), radius_(radius), height_(height) {}

    double getRadius() const { return radius_; }
    double getHeight() const { return height_; }

    double calculateSurfaceArea() const override {
        return 2 * M_PI * radius_ * (radius_ + sqrt(pow(radius_, 2) + pow(height_, 2)));
    }

    double calculateVolume() const override {
        return M_PI * pow(radius_, 2) * height_;
    }

private:
    double radius_;
    double height_;
};

#endif // CONE_HPP
