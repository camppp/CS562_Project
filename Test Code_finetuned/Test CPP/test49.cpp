#include <Eigen/Dense>
#include <sstream>
#include <stdexcept>

template <std::size_t N>
Eigen::Matrix<double, N, 1> toVectorNd(const std::string& str) {
    Eigen::Matrix<double, N, 1> vec;
    std::istringstream iss(str);
    double val;
    int i = 0;

    while (iss >> val) {
        if (i >= N) {
            throw std::invalid_argument("Too many values in input string");
        }
        vec(i++) = val;
    }

    if (i!= N) {
        throw std::invalid_argument("Not enough values in input string");
    }

    if (iss.fail() &&!iss.eof()) {
        throw std::runtime_error("Error parsing input string");
    }

    return vec;
}