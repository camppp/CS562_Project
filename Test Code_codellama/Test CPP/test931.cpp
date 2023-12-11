#include <iostream>
#include <Eigen/Dense>

Eigen::MatrixXf convertToMatrix(const std::vector<float>& optThetaData, int featureSize) {
    Eigen::MatrixXf optTheta(featureSize, 1);
    for (int i = 0; i < featureSize; i++) {
        optTheta(i, 0) = optThetaData[i];
    }
    return optTheta;
}

int main() {
    std::vector<float> optThetaData = {1.0, 2.0, 3.0, 4.0};
    int featureSize = 4;
    Eigen::MatrixXf result = convertToMatrix(optThetaData, featureSize);
    std::cout << result << std::endl;
    return 0;
}
