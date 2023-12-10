void compare_normal_derivative(double delta, BicubicPatch* patch, Vector3 base_normal, int resolution, Vector3 analytic_full_deriv) {
    // Backup original values for restoration after comparison
    double backup_f = patch->n01->f;
    Vector3 backup_dx = patch->n01->dx;

    // Calculate the normal derivative with a small change in parameter value
    patch->n01->f += delta;
    Vector3 perturbed_normal = patch->calculateNormal();
    Vector3 numerical_deriv = (perturbed_normal - base_normal) / delta;

    // Restore original parameter value
    patch->n01->f = backup_f;

    // Compare the numerical derivative with the analytically calculated full derivative
    double error = (numerical_deriv - analytic_full_deriv).length();

    // Output the comparison result
    if (error < resolution) {
        std::cout << "Normal derivative comparison passed with error: " << error << std::endl;
    } else {
        std::cout << "Normal derivative comparison failed with error: " << error << std::endl;
    }

    // Restore original dx value
    patch->n01->dx = backup_dx;
}
