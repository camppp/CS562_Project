#include <iostream>
#include <string>
#include <stdexcept>

class UnsupportedIMUException : public std::runtime_error {
public:
    UnsupportedIMUException(const std::string& message) : std::runtime_error(message) {}
};

double processIMUData(const std::string& imu_type, const std::vector<double>& raw_data) {
    if (imu_type == "accelerometer") {
        // Process accelerometer data
        double magnitude = calculate_acceleration_magnitude(raw_data);
        return magnitude;
    } else if (imu_type == "gyroscope") {
        // Process gyroscope data
        double avg_angular_velocity = calculate_average_angular_velocity(raw_data);
        return avg_angular_velocity;
    } else if (imu_type == "magnetometer") {
        // Process magnetometer data
        double total_magnetic_field = calculate_total_magnetic_field(raw_data);
        return total_magnetic_field;
    } else {
        throw UnsupportedIMUException("Unsupported IMU type");
    }
}
