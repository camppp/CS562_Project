#include <iostream>

class Vec3 {
public:
    double x, y, z;

    Vec3(double x, double y, double z) : x(x), y(y), z(z) {}

    Vec3 operator+(const Vec3 &other) const {
        return Vec3(x + other.x, y + other.y, z + other.z);
    }

    Vec3 &operator+=(const Vec3 &other) {
        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
    }
};

int main() {
    Vec3 v1(1.0, 2.0, 3.0);
    Vec3 v2(4.0, 5.0, 6.0);

    Vec3 sum = v1 + v2;
    std::cout << "Sum: (" << sum.x << ", " << sum.y << ", " << sum.z << ")" << std::endl;

    v1 += v2;
    std::cout << "v1 after addition: (" << v1.x << ", " << v1.y << ", " << v1.z << ")" << std::endl;

    return 0;
}
