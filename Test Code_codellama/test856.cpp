void compare_normal_derivative(double delta, BicubicPatch* patch, Vector3 base_normal, int resolution, Vector3 analytic_full_deriv) {
    // Calculate the numerical derivative using finite differences
    Vector3 numerical_full_deriv = calculate_numerical_full_derivative(patch, base_normal, resolution, delta);

    // Calculate the difference between the numerical and analytic derivatives
    Vector3 diff = numerical_full_deriv - analytic_full_deriv;

    // Print the difference and the maximum absolute value of the difference
    std::cout << "Difference: " << diff << std::endl;
    std::cout << "Maximum absolute value: " << std::max(std::abs(diff.x), std::max(std::abs(diff.y), std::abs(diff.z))) << std::endl;
}
