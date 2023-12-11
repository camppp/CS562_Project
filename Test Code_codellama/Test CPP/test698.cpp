void addSuitableDevices(std::vector<SuitableDevice>& suitableDevices, const std::vector<SuitableDevice>& newDevices, int minCapability) {
    for (const auto& device : newDevices) {
        if (device.getCapability() >= minCapability) {
            suitableDevices.push_back(device);
        }
    }
}
