#include <vector>

class SuitableDevice {
    int capability;
    // Other device specifications
public:
    SuitableDevice(int cap) : capability(cap) {}
    int getCapability() const { return capability; }
    // Other member functions
};

void addSuitableDevices(std::vector<SuitableDevice>& suitableDevices, const std::vector<SuitableDevice>& newDevices, int minCapability) {
    for (const auto& device : newDevices) {
        if (device.getCapability() >= minCapability) {
            suitableDevices.push_back(device);
        }
    }
}
