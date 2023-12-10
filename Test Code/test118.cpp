#include "iioservice/libiioservice_ipc/sensor_client.h"
#include <memory>

std::string processSensorData(const std::string& sensorId) {
    std::string rawSensorData = retrieveSensorData(sensorId);

    if (rawSensorData.find("error") != std::string::npos) {
        return "Error: Sensor data retrieval failed";
    } else if (rawSensorData.find("low_battery") != std::string::npos) {
        return "Warning: Low battery detected";
    } else if (rawSensorData.find("normal") != std::string::npos) {
        return "Sensor data is normal";
    } else {
        return "Unknown sensor data";
    }
}
