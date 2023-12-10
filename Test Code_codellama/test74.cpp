#include <iostream>
#include <cmath>

class Point3D {
private:
    double x;
    double y;
    double z;

public:
    Point3D(double x, double y, double z) : x(x), y(y), z(z) {}

    double distanceTo(const Point3D& other) {
        double dx = x - other.x;
        double dy = y - other.y;
        double dz = z - other.z;
        return std::sqrt(dx * dx + dy * dy + dz * dz);
    }
};
