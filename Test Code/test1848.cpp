#include <cppad/cppad.hpp>

// Function to perform higher-order automatic differentiation
CPPAD_TESTVECTOR(double) performHigherOrderDifferentiation(int n, int m, const CPPAD_TESTVECTOR(double)& a1x, const CPPAD_TESTVECTOR(double)& a2x, const CPPAD_TESTVECTOR(double)& a2y) {
    // Declare independent variables at the first level
    CppAD::Independent(a1x);

    // Start a2 level recording
    CPPAD_TESTVECTOR(CppAD::AD<double>) a2x_AD(n), a2y_AD(m);
    for(size_t j = 0; j < n; j++)
        a2x_AD[j] = a2x[j];
    CppAD::Independent(a2x_AD);

    // Declare dependent variables at the second level
    CppAD::ADFun<double> f(a1x, a2y);
    f.Dependent(a2x_AD);

    // Compute second-level derivatives
    CPPAD_TESTVECTOR(double) a2x_AD_val(n);
    for(size_t j = 0; j < n; j++)
        a2x_AD_val[j] = a2x_AD[j].value();
    CPPAD_TESTVECTOR(double) a2y_AD_deriv = f.Jacobian(a2x_AD_val);

    return a2y_AD_deriv;
}

int main() {
    int n = 2; // Number of independent variables
    int m = 1; // Number of dependent variables
    CPPAD_TESTVECTOR(double) a1x(n), a2x(n), a2y(m);

    // Initialize independent variables
    a1x[0] = 1.0;
    a1x[1] = 2.0;

    // Initialize independent variables at the second level
    a2x[0] = 3.0;
    a2x[1] = 4.0;

    // Initialize dependent variables at the second level
    a2y[0] = 5.0;

    // Perform higher-order automatic differentiation
    CPPAD_TESTVECTOR(double) result = performHigherOrderDifferentiation(n, m, a1x, a2x, a2y);

    // Print the second-level derivatives
    for (size_t i = 0; i < result.size(); i++) {
        std::cout << "Second-level derivative of y with respect to x" << i << ": " << result[i] << std::endl;
    }

    return 0;
}
