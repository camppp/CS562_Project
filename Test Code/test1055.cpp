void startIMU(bool readTrimData) {
    device.sensorPowerOn();
    if (readTrimData) {
        // Read trim data during initialization
        // Implement the logic to read trim data here
    }
}
