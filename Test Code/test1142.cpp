#include <string>

class Device {
private:
    std::string deviceName;

public:
    Device(const std::string& hostname) : deviceName(hostname) {}

    const std::string& getDeviceName() const {
        return deviceName;
    }
};
