#include <iostream>
#include <cmath>
#include <functional>
#include <cassert>

// Example implementation of vec3 class
class vec3 {
public:
    float x, y, z;
    vec3(float x, float y, float z) : x(x), y(y), z(z) {}
};

// Example implementation of constants class
template <typename T>
class constants {
public:
    static T pi() { return T(3.14159265359); }
};

// Example implementation of mat4 class
class mat4 {
public:
    float data[4][4];

    // Example implementation of rotation method
    static mat4 rotation(const vec3& axis, float angle) {
        mat4 result;
        // Implementation details for rotation
        // ...
        return result;
    }

    // Transpose function for mat4 class
    mat4 transpose() const {
        mat4 result;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                result.data[i][j] = data[j][i];
            }
        }
        return result;
    }

    // Example implementation of operator() for accessing elements
    float& operator()(int i, int j) {
        return data[i][j];
    }
};

// Example implementation of test framework
template <typename Func>
void for_each_mat4_e(Func func) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            func(i, j);
        }
    }
}

// Example implementation of EXPECT_FLOAT_EQ macro
#define EXPECT_FLOAT_EQ(actual, expected) \
    do { \
        if (std::abs(actual - expected) > 1e-6) { \
            std::cerr << "Test failed: " << actual << " != " << expected << std::endl; \
            assert(false); \
        } \
    } while (0)

int main() {
    // make some non-singular matrix
    mat4 A = mat4::rotation(vec3(1, 0, 0), constants<float>::pi() / 4);
    mat4 B = A.transpose();

    for_each_mat4_e(
        [&](int i, int j)
        {
            EXPECT_FLOAT_EQ(A(i, j), B(j, i));
        }
    );

    std::cout << "Transpose function passed the test." << std::endl;

    return 0;
}
