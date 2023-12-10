bool Context::create(EDeviceType type) {
    // Create a new device of the specified type
    Device device(type);

    // Assign a unique ID to the device
    device.setId(_id++);

    // Add the device to the collection
    _devs.push_back(device);

    return true;
}
