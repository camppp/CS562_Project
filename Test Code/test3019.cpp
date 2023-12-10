#include <iostream>
#include <cmath>

class SVector5 {
private:
    double values[5];

public:
    SVector5(double v1, double v2, double v3, double v4, double v5) {
        values[0] = v1;
        values[1] = v2;
        values[2] = v3;
        values[3] = v4;
        values[4] = v5;
    }

    double dotProduct(const SVector5& other) const {
        double result = 0;
        for (int i = 0; i < 5; ++i) {
            result += values[i] * other.values[i];
        }
        return result;
    }

    SVector5 crossProduct(const SVector5& other) const {
        SVector5 result(0, 0, 0, 0, 0);
        result.values[0] = values[1] * other.values[2] - values[2] * other.values[1];
        result.values[1] = values[2] * other.values[0] - values[0] * other.values[2];
        result.values[2] = values[0] * other.values[1] - values[1] * other.values[0];
        return result;
    }

    double magnitude() const {
        double sum = 0;
        for (int i = 0; i < 5; ++i) {
            sum += values[i] * values[i];
        }
        return std::sqrt(sum);
    }

    SVector5 normalize() const {
        double mag = magnitude();
        SVector5 result(0, 0, 0, 0, 0);
        for (int i = 0; i < 5; ++i) {
            result.values[i] = values[i] / mag;
        }
        return result;
    }
};

int main() {
    SVector5 v1(1, 2, 3, 4, 5);
    SVector5 v2(5, 4, 3, 2, 1);

    std::cout << "Dot product: " << v1.dotProduct(v2) << std::endl;

    SVector5 cross = v1.crossProduct(v2);
    std::cout << "Cross product: (" << cross.values[0] << ", " << cross.values[1] << ", " << cross.values[2] << ")" << std::endl;

    std::cout << "Magnitude of v1: " << v1.magnitude() << std::endl;

    SVector5 normalized = v2.normalize();
    std::cout << "Normalized v2: (" << normalized.values[0] << ", " << normalized.values[1] << ", " << normalized.values[2] << ", " << normalized.values[3] << ", " << normalized.values[4] << ")" << std::endl;

    return 0;
}
