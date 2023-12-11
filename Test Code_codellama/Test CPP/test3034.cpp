#include <iostream>
#include <cmath>

// Matrix4 class
class Matrix4 {
public:
    float m[4][4];

    Matrix4() {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                m[i][j] = 0.0f;
            }
        }
    }

    Matrix4(float m00, float m01, float m02, float m03,
            float m10, float m11, float m12, float m13,
            float m20, float m21, float m22, float m23,
            float m30, float m31, float m32, float m33) {
        m[0][0] = m00; m[0][1] = m01; m[0][2] = m02; m[0][3] = m03;
        m[1][0] = m10; m[1][1] = m11; m[1][2] = m12; m[1][3] = m13;
        m[2][0] = m20; m[2][1] = m21; m[2][2] = m22; m[2][3] = m23;
        m[3][0] = m30; m[3][1] = m31; m[3][2] = m32; m[3][3] = m33;
    }

    Matrix4 operator*(const Matrix4& other) const {
        Matrix4 result;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                result.m[i][j] = m[i][0] * other.m[0][j] +
                                 m[i][1] * other.m[1][j] +
                                 m[i][2] * other.m[2][j] +
                                 m[i][3] * other.m[3][j];
            }
        }
        return result;
    }

    void print() {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                std::cout << m[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

// Point3 class
class Point3 {
public:
    float x, y, z;

    Point3() {
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
    }

    Point3(float x, float y, float z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    Point3 operator+(const Point3& other) const {
        return Point3(x + other.x, y + other.y, z + other.z);
    }

    Point3 operator-(const Point3& other) const {
        return Point3(x - other.x, y - other.y, z - other.z);
    }

    Point3 operator*(const float& scalar) const {
        return Point3(x * scalar, y * scalar, z * scalar);
    }

    void print() {
        std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl;
    }
};

// Implement the missing logic inside the pitch function to update the pitchAmount based on the given amt parameter
void pitch(float amt) {
    // Calculate the sine and cosine of the pitch angle
    float sinPitch = sin(amt);
    float cosPitch = cos(amt);

    // Calculate the new pitch amount
    pitchAmount = amt;

    // Update the view matrix
    viewMatrix = Matrix4(
        cosPitch, 0.0f, -sinPitch, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        sinPitch, 0.0f, cosPitch, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    );
}

// Implement the missing logic inside the updateMatrices function to calculate the view and projection matrices using the provided Matrix4 and Point3 classes
void updateMatrices() {
    // Calculate the view matrix
    viewMatrix = Matrix4(
        cos(pitchAmount), 0.0f, -sin(pitchAmount), 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        sin(pitchAmount), 0.0f, cos(pitchAmount), 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    );

    // Calculate the projection matrix
    projectionMatrix = Matrix4(
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    );

    // Calculate the view-projection matrix
    vpMatrix = viewMatrix * projectionMatrix;
}
