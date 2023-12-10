#include <iostream>
#include <string>

enum class DeviceType {
    MOBILE,
    TABLET,
    LAPTOP,
    CAR,
    UNKNOWN
};

class SystemProperties {
private:
    DeviceType deviceType;

public:
    SystemProperties() : deviceType(DeviceType::UNKNOWN) {}

    DeviceType GetDeviceType() const {
        return deviceType;
    }

    void InitDeviceType(DeviceType type) {
        deviceType = type;
    }
};

int main() {
    SystemProperties properties;
    properties.InitDeviceType(DeviceType::CAR);
    std::cout << "Device Type: " << static_cast<int>(properties.GetDeviceType()) << std::endl;
    return 0;
}
