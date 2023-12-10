#include <iostream>
#include <Eigen/Dense>

Eigen::MatrixXd elementWiseMultiplication(const Eigen::MatrixXd& a, const Eigen::MatrixXd& b) {
  // Check if both matrices have the same dimensions
  if (a.rows() != b.rows() || a.cols() != b.cols()) {
    // Handle different dimensions
    if (a.rows() == 1 && a.cols() == b.cols()) {
      // Matrix a is a row vector and has the same number of columns as matrix b
      return a.array().rowwise() * b.array();
    } else if (b.rows() == 1 && b.cols() == a.cols()) {
      // Matrix b is a row vector and has the same number of columns as matrix a
      return a.array() * b.array().rowwise();
    } else {
      // Handle other scenarios
      std::cout << "Error: matrices have different dimensions" << std::endl;
      return Eigen::MatrixXd();
    }
  } else {
    // Handle same dimensions
    return a.array() * b.array();
  }
}
