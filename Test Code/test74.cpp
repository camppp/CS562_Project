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

int main() {
    Point3D point1(1.0, 2.0, 3.0);
    Point3D point2(4.0, 5.0, 6.0);

    double distance = point1.distanceTo(point2);
    std::cout << "Distance between the two points: " << distance << std::endl;

    return 0;
}
