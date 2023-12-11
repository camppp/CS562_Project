void sensorDataSynchronization(OrbSubscriptionHandle accel_sub, OrbSubscriptionHandle gyro_sub) {
  bool accel_updated = false;
  bool gyro_updated = false;

  // Check for updated data from the accelerometer
  if (orb_check(accel_sub, &accel_updated)) {
    // If new data is available, set the flag to true
    if (accel_updated) {
      // Perform further processing (e.g., sensor fusion)
      processSensorData(accel_sub);
    }
  }

  // Check for updated data from the gyroscope
  if (orb_check(gyro_sub, &gyro_updated)) {
    // If new data is available, set the flag to true
    if (gyro_updated) {
      // Perform further processing (e.g., sensor fusion)
      processSensorData(gyro_sub);
    }
  }

  // If both accelerometer and gyroscope data have been updated,
  // perform further processing (e.g., sensor fusion)
  if (accel_updated && gyro_updated) {
    processSensorData(accel_sub, gyro_sub);
  }
}
