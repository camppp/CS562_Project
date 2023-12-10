#include <iostream>

class motor_api {
protected:
    int x, y, z;

public:
    motor_api(int x, int y, int z) : x(x), y(y), z(z) {}

    void set3D(int x, int y, int z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }
};

class Output {
    // Define the Output class if necessary
};

class UInt2 : public motor_api, public Output {
    int value;

public:
    UInt2(int x, int y, int z, int value) : motor_api(x, y, z), value(value) {}

    void setUInt2(int value) {
        this->value = value;
    }
};

int main() {
    // Example usage
    UInt2 motor(1, 2, 3, 10);
    motor.set3D(4, 5, 6);
    motor.setUInt2(20);
    return 0;
}
