void sensorDataSynchronization(int _accel_sub, int _gyro_sub) {
    bool accel_updated = false;
    bool gyro_updated = false;

    orb_check(_accel_sub, &accel_updated); // Check for updated data from the accelerometer
    orb_check(_gyro_sub, &gyro_updated);   // Check for updated data from the gyroscope

    if (accel_updated && gyro_updated) {
        // Both accelerometer and gyroscope data have been updated, perform further processing
        processSensorData();
    }
}
