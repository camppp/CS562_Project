Eigen::MatrixXd computeNumericalJacobian(const Eigen::VectorXd& params, const double step, const Eigen::VectorXd& error, const Eigen::MatrixXd& T_OL, const ResidualFunction& residual) {
    Eigen::MatrixXd T_OL_jacobian_numeric(error.size(), params.size());

    for (int i = 0; i < params.size(); ++i) {
        Eigen::VectorXd perturb = Eigen::VectorXd::Zero(params.size());
        perturb(i) = step;
        Eigen::MatrixXd perturbed_error;
        residual.Evaluate(params + perturb, perturbed_error.data(), nullptr);
        T_OL.manifoldPlus(perturb);
        T_OL_jacobian_numeric.col(i) = (perturbed_error - error) / step;
    }

    return T_OL_jacobian_numeric;
}
