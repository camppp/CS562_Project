#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <Eigen/Dense>

struct CameraParams {
    double b;
    double fu;
    double fv;
    double cu;
    double cv;
};

struct SensorData {
    CameraParams camParams;
    Eigen::Matrix4d noise;
    // Additional fields for stereo camera measurements if needed
    // ...
};

SensorData parseSensorData(const std::vector<std::string>& sensorData) {
    SensorData data;

    for (const auto& line : sensorData) {
        std::string type = line.substr(0, line.find(' '));
        std::string params = line.substr(line.find(' ') + 1);

        if (type == "CAMERA") {
            data.camParams.b = std::stod(params.substr(0, params.find(' ')));
            data.camParams.fu = std::stod(params.substr(params.find(' ') + 1, params.find(' ')));
            data.camParams.fv = std::stod(params.substr(params.find(' ') + 1, params.find(' ')));
            data.camParams.cu = std::stod(params.substr(params.find(' ') + 1, params.find(' ')));
            data.camParams.cv = std::stod(params.substr(params.find(' ') + 1, params.find(' ')));
        } else if (type == "DIAGNOISE") {
            data.noise.diagonal() = Eigen::Vector4d::Map(params.data());
        } else if (type == "STEREO") {
            // Additional fields for stereo camera measurements if needed
            // ...
        }
    }

    return data;
}

int main() {
    std::vector<std::string> sensorData = {
        "CAMERA 1.0 2.0 3.0 4.0 5.0",
        "DIAGNOISE 1.0 2.0 3.0 4.0",
        "STEREO 1.0 2.0 3.0 4.0 5.0 6.0 7.0 8.0"
    };

    SensorData data = parseSensorData(sensorData);

    std::cout << "Camera parameters: " << std::endl;
    std::cout << "b: " << data.camParams.b << std::endl;
    std::cout << "fu: " << data.camParams.fu << std::endl;
    std::cout << "fv: " << data.camParams.fv << std::endl;
    std::cout << "cu: " << data.camParams.cu << std::endl;
    std::cout << "cv: " << data.camParams.cv << std::endl;

    std::cout << "Noise covariance matrix: " << std::endl;
    std::cout << data.noise << std::endl;

    // Additional fields for stereo camera measurements if needed
    // ...

    return 0;
}
