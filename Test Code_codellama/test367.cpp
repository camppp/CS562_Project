#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Custom vector class
template <typename T>
class Vector {
public:
    T x, y, z;

    // Constructor
    Vector(T x, T y, T z) : x(x), y(y), z(z) {}

    // Dot product
    T dot(const Vector<T>& other) const {
        return x * other.x + y * other.y + z * other.z;
    }

    // Matrix multiplication
    Vector<T> operator*(const Matrix<T>& other) const {
        return Vector<T>(x * other.x, y * other.y, z * other.z);
    }
};

// Custom matrix class
template <typename T>
class Matrix {
public:
    T x, y, z;

    // Constructor
    Matrix(T x, T y, T z) : x(x), y(y), z(z) {}

    // Matrix multiplication
    Matrix<T> operator*(const Matrix<T>& other) const {
        return Matrix<T>(x * other.x, y * other.y, z * other.z);
    }
};

// Function to solve a system of linear equations involving positive definite matrices
Vector<double> solvePositiveDefinite(const Matrix<double>& Lff, const Vector<double>& rhs) {
    // Calculate the inverse of the matrix Lff
    Matrix<double> invLff = Lff.inverse();

    // Calculate the solution vector Gn
    Vector<double> Gn = invLff * rhs;

    return Gn;
}

// Function to calculate cone angles based on the given matrix and vector operations
void calculateConeAngles(const Matrix<double>& Lff, const Vector<double>& omegaFlat) {
    // Calculate the inverse of the matrix Lff
    Matrix<double> invLff = Lff.inverse();

    // Calculate the solution vector Gn
    Vector<double> Gn = invLff * omegaFlat;

    // Calculate the cone angles
    double coneAngle1 = acos(Gn.x / Gn.length());
    double coneAngle2 = acos(Gn.y / Gn.length());
    double coneAngle3 = acos(Gn.z / Gn.length());

    // Print the cone angles
    cout << "Cone angles: " << coneAngle1 << ", " << coneAngle2 << ", " << coneAngle3 << endl;
}

int main() {
    // Define the positive definite matrix Lff
    Matrix<double> Lff(1, 2, 3);

    // Define the vector omegaFlat
    Vector<double> omegaFlat(1, 2, 3);

    // Solve the system of linear equations involving Lff and omegaFlat
    Vector<double> Gn = solvePositiveDefinite(Lff, omegaFlat);

    // Calculate the cone angles based on the solution vector Gn
    calculateConeAngles(Lff, omegaFlat);

    return 0;
}
