#include <stdexcept>
#include <string>
#include <vector>

template <std::size_t N>
Eigen::Matrix<double, N, 1> toVectorNd(const std::string& str) {
    std::vector<double> values;
    std::stringstream ss(str);
    double value;
    while (ss >> value) {
        values.push_back(value);
    }
    if (values.size() != N) {
        throw std::invalid_argument("Invalid number of double values in input string");
    }
    Eigen::Matrix<double, N, 1> result;
    for (std::size_t i = 0; i < N; ++i) {
        result(i) = values[i];
    }
    return result;
}
