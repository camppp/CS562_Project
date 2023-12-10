#include <Eigen/Dense>

Eigen::Vector3d computeLinearCombination(const Eigen::Vector3d& x1, const Eigen::Vector3d& x2, double alpha1, double alpha2, double beta1, double beta2, double gamma2) {
    double gamma1 = 1.0 - gamma2;
    Eigen::Vector3d result;
    result << (alpha1 * x1.x() + alpha2 * x2.x()), (beta1 * x1.y() + beta2 * x2.y()), (gamma1 * x1.z() + gamma2 * x2.z());
    return result;
}
