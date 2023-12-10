#include <iostream>
#include <string>
#include "sensor_client.h"

std::string processSensorData(const std::string& sensorId) {
    // Retrieve the raw sensor data
    std::string sensorData = retrieveSensorData(sensorId);

    // Check if the sensor data contains the string "error"
    if (sensorData.find("error") != std::string::npos) {
        return "Error: Sensor data retrieval failed";
    }

    // Check if the sensor data contains the string "low_battery"
    if (sensorData.find("low_battery") != std::string::npos) {
        return "Warning: Low battery detected";
    }

    // Check if the sensor data contains the string "normal"
    if (sensorData.find("normal") != std::string::npos) {
        return "Sensor data is normal";
    }

    // For any other sensor data, return "Unknown sensor data"
    return "Unknown sensor data";
}
