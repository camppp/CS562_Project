#include <Eigen/Dense>
#include <vector>

Eigen::MatrixXf convertToMatrix(const std::vector<float>& optThetaData, int featureSize) {
    Eigen::MatrixXf optTheta(featureSize, 1);
    for(int i = 0; i < featureSize; i++) {
        optTheta(i, 0) = optThetaData[i];
    }
    return optTheta;
}
