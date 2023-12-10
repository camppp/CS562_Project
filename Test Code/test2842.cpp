class SystemProperties {
private:
    int deviceType;

public:
    SystemProperties() {}

    void InitDeviceType(int deviceType) {
        this->deviceType = deviceType;
    }

    int GetDeviceType() {
        return deviceType;
    }
};
