#include <iostream>
#include <cmath>

struct Vec {
    double x, y, z;
};

struct Vec2 {
    double x, y;
};

struct Vec3 {
    double x, y, z;
};

struct Apply3 {
    inline void operator()(Vec& vec, const Vec2& vec2, const Vec3& vec3) const {
        vec.x += vec2.x;
        vec.y -= vec2.y;
        vec.z *= sqrt(vec3.x * vec3.x + vec3.y * vec3.y + vec3.z * vec3.z);
    }
};

int main() {
    Vec vector = {1.0, 2.0, 3.0};
    Vec2 vector2 = {0.5, 1.0};
    Vec3 vector3 = {1.0, 2.0, 3.0};

    Apply3 transformation;
    transformation(vector, vector2, vector3);

    std::cout << "Transformed vector: (" << vector.x << ", " << vector.y << ", " << vector.z << ")" << std::endl;

    return 0;
}
