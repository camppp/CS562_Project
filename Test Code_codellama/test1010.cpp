class Angle {
private:
    float degrees;
    float radians;

public:
    Angle(float degrees) {
        this->degrees = degrees;
        this->radians = degrees * (float)M_PI / 180.0;
    }

    operator float() {
        return degrees;
    }

    operator Degree() {
        return Degree(degrees);
    }

    operator Radian() {
        return Radian(radians);
    }
};
