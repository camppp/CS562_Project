#include <iostream>
#include <string>

class motor_api {
public:
    motor_api() {}
    ~motor_api() {}

    void set_3D(const std::string& value) {
        this->value = value;
    }

    std::string get_3D() {
        return this->value;
    }

private:
    std::string value;
};

class UInt2 : public motor_api, public Output {
public:
    UInt2() {}
    ~UInt2() {}

    void set_UInt2(const std::string& value) {
        this->value = value;
    }

    std::string get_UInt2() {
        return this->value;
    }

private:
    std::string value;
};
