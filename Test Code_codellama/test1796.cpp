#include <iostream>
#include <Eigen/Dense>

double calculateSquaredDistance(const std::vector<double>& vec1, const std::vector<double>& vec2) {
    Eigen::Map<Eigen::MatrixXd> mat1(vec1.data(), vec1.size(), 1);
    Eigen::Map<Eigen::MatrixXd> mat2(vec2.data(), vec2.size(), 1);
    return (mat1 - mat2).squaredNorm();
}

int main() {
    std::vector<double> vec1 = {1.0, 2.0, 3.0};
    std::vector<double> vec2 = {4.0, 5.0, 6.0};
    double distance = calculateSquaredDistance(vec1, vec2);
    std::cout << "Squared distance: " << distance << std::endl;
    return 0;
}
