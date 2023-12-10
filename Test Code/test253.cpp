#include <iostream>
#include <vector>
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
    SensorData result;

    for (auto it = sensorData.begin(); it != sensorData.end(); ++it) {
        if (it->find("CAMERA") == 0) {
            unsigned int i = 1;
            result.camParams.b  = atof(it->at(i++).c_str());
            result.camParams.fu = atof(it->at(i++).c_str());
            result.camParams.fv = atof(it->at(i++).c_str());
            result.camParams.cu = atof(it->at(i++).c_str());
            result.camParams.cv = atof(it->at(i).c_str());
        } else if (it->find("DIAGNOISE") == 0) {
            result.noise = Eigen::Matrix4d::Zero();
            unsigned int i = 1;
            for (int j = 0; j < 4; ++j) {
                result.noise(j, j) = atof(it->at(i++).c_str());
            }
        } else if (it->find("STEREO") == 0) {
            // Handle stereo camera measurements if needed
            // ...
        }
    }

    return result;
}
