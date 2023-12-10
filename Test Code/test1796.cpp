#include <vector>
#include <Eigen/Dense>

double calculateSquaredDistance(const std::vector<double>& vec1, const std::vector<double>& vec2) {
    // Check if the input vectors have the same size
    if (vec1.size() != vec2.size()) {
        throw std::invalid_argument("Input vectors must have the same size");
    }

    // Convert input vectors to Eigen vectors for efficient computation
    Eigen::Map<const Eigen::VectorXd> eigenVec1(vec1.data(), vec1.size());
    Eigen::Map<const Eigen::VectorXd> eigenVec2(vec2.data(), vec2.size());

    // Calculate the squared distance using Eigen library
    double squaredDistance = (eigenVec1 - eigenVec2).squaredNorm();

    return squaredDistance;
}
