#include <iostream>
#include <cmath>

class Radian {
    double value;

public:
    explicit Radian(double val) : value(val) {}

    operator double() const {
        return value;
    }
};

class Degree {
    double value;

public:
    explicit Degree(double val) : value(val) {}

    operator double() const {
        return value;
    }
};

class Angle {
    double degrees;
    double radians;

public:
    Angle(double deg) : degrees(deg), radians(deg * M_PI / 180) {}

    operator float() const {
        return static_cast<float>(degrees);
    }

    explicit operator Degree() const {
        return Degree(degrees);
    }

    explicit operator Radian() const {
        return Radian(radians);
    }
};

int main() {
    Angle angle(90);
    float deg = angle; // Implicit conversion to float
    Degree degObj = static_cast<Degree>(angle); // Explicit conversion to Degree
    Radian radObj = static_cast<Radian>(angle); // Explicit conversion to Radian

    std::cout << "Angle in degrees: " << deg << std::endl;
    std::cout << "Angle in degrees (Degree object): " << static_cast<double>(degObj) << std::endl;
    std::cout << "Angle in radians (Radian object): " << static_cast<double>(radObj) << std::endl;

    return 0;
}
