#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;

// Define the residual error function
struct ResidualFunction {
  VectorXd operator()(const VectorXd& params) const {
    // Compute the error between the actual and desired positions of the end effector
    VectorXd error = params - params.transpose();
    return error;
  }
};

// Define the numerical differentiation method
Eigen::MatrixXd computeNumericalJacobian(const Eigen::VectorXd& params, const double step, const Eigen::VectorXd& error, const Eigen::MatrixXd& T_OL, const ResidualFunction& residual) {
  // Initialize the Jacobian matrix
  Eigen::MatrixXd T_OL_jacobian_numeric(params.size(), params.size());

  // Loop over the input parameters and compute the perturbed error
  for (int i = 0; i < params.size(); i++) {
    // Perturb the input parameters
    VectorXd perturbed_params = params;
    perturbed_params(i) += step;

    // Compute the perturbed error
    VectorXd perturbed_error = residual(perturbed_params);

    // Compute the partial derivative of the error with respect to the input parameters
    double partial_derivative = (perturbed_error - error) / step;

    // Store the partial derivative in the Jacobian matrix
    T_OL_jacobian_numeric(i, i) = partial_derivative;
  }

  return T_OL_jacobian_numeric;
}

int main() {
  // Define the input parameters
  VectorXd params(3);
  params << 1, 2, 3;

  // Define the perturbation step size
  double step = 1e-6;

  // Define the error between the actual and desired positions of the end effector
  VectorXd error(3);
  error << 0.1, 0.2, 0.3;

  // Define the transformation from the object frame to the end effector frame
  MatrixXd T_OL(4, 4);
  T_OL << 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1;

  // Define the residual error function
  ResidualFunction residual;

  // Compute the numerical Jacobian matrix
  Eigen::MatrixXd T_OL_jacobian_numeric = computeNumericalJacobian(params, step, error, T_OL, residual);

  // Print the numerical Jacobian matrix
  std::cout << "Numerical Jacobian Matrix: " << std::endl << T_OL_jacobian_numeric << std::endl;

  return 0;
}
