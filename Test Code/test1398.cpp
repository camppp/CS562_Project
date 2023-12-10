#include <Eigen/Dense>

Eigen::MatrixXd elementWiseMultiplication(const Eigen::MatrixXd& a, const Eigen::MatrixXd& b) {
    if (a.rows() == b.rows() && a.cols() == b.cols()) {
        // Case 1: Both matrices have the same dimensions
        return a.array() * b.array();
    } else if ((a.rows() == 1) && (a.cols() == b.cols())) {
        // Case 2: Row-wise broadcast from a
        Eigen::Map<Eigen::RowVectorXd> a_vector(a.data(), a.cols());
        return b.array().rowwise() * a_vector.array();
    } else if ((b.rows() == 1) && (a.cols() == b.cols())) {
        // Case 3: Row-wise broadcast from b
        Eigen::Map<Eigen::RowVectorXd> b_vector(b.data(), b.cols());
        return a.array().rowwise() * b_vector.array();
    } else {
        // Handle invalid input dimensions
        throw std::invalid_argument("Invalid input dimensions for element-wise multiplication");
    }
}
