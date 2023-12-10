#include <Eigen/Dense>
#include <sstream>
#include <stdexcept>

template <std::size_t N>
Eigen::Matrix<double, N, 1> toVectorNd(const std::string& str) {
    Eigen::Matrix<double, N, 1> result;

    std::istringstream iss(str);
    double value;
    std::size_t count = 0;
    while (iss >> value) {
        if (count >= N) {
            throw std::invalid_argument("Input string contains more values than the specified vector size");
        }
        result(count, 0) = value;
        count++;
    }

    if (count != N) {
        throw std::invalid_argument("Input string does not contain enough values for the specified vector size");
    }

    if (!iss.eof()) {
        throw std::runtime_error("Error parsing input string");
    }

    return result;
}
