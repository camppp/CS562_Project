python
class UnsupportedIMUException(Exception):
    pass

def processIMUData(imu_type, raw_data):
    if imu_type == "accelerometer":
        # Process accelerometer data
        magnitude = calculate_acceleration_magnitude(raw_data)
        return magnitude
    elif imu_type == "gyroscope":
        # Process gyroscope data
        avg_angular_velocity = calculate_average_angular_velocity(raw_data)
        return avg_angular_velocity
    elif imu_type == "magnetometer":
        # Process magnetometer data
        total_magnetic_field = calculate_total_magnetic_field(raw_data)
        return total_magnetic_field
    else:
        raise UnsupportedIMUException("Unsupported IMU type")
