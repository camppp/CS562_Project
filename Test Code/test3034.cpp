#include <iostream>
#include <cmath>

// Assume the following definitions for Matrix4 and Point3 classes
class Matrix4 {
public:
    static Matrix4 lookAt(const Point3& eye, const Point3& target, const Vector3& up) {
        // Implementation of lookAt function to create a view matrix
        // This function returns a view matrix based on the given eye position, target position, and up vector
    }
};

class Point3 {
public:
    float x, y, z;
};

class Vector3 {
public:
    float x, y, z;
};

// Assume the following global variables
float pitchAmount = 0.0f;
Matrix4 viewMatrix;
Matrix4 projMatrix;
Matrix4 vpMatrix;
Point3 eye;
Point3 lookAtTarget();
Vector3 up;

void pitch(float amt) {
    pitchAmount += amt;
}

void updateMatrices() {
    viewMatrix = Matrix4::lookAt(eye, lookAtTarget(), -up);
    vpMatrix = projMatrix * viewMatrix; // Vectormath lib uses column-major OGL style, so multiply P*V*M
}
