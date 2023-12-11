#include <iostream>
#include <vector>
#include <cmath>

class SparseLinearSolver {
public:
    // Constructor
    SparseLinearSolver(int n) : n_(n) {
        // Initialize the matrix and solver
        matrix_ = new double[n_ * n_];
        solver_ = new double[n_];
    }

    // Destructor
    ~SparseLinearSolver() {
        // Delete the matrix and solver
        delete[] matrix_;
        delete[] solver_;
    }

    // Set up the solver using the Conjugate Gradient method
    void setUpSolver() {
        // Initialize the solver
        for (int i = 0; i < n_; i++) {
            solver_[i] = 0;
        }

        // Compute the residual norm
        double residual_norm = 1;

        // Iterate until the residual norm is below a tolerance
        while (residual_norm > 1e-6) {
            // Compute the conjugate direction
            double conjugate_direction = 0;
            for (int i = 0; i < n_; i++) {
                conjugate_direction += matrix_[i * n_ + i] * solver_[i];
            }
            conjugate_direction /= matrix_[n_ * n_ - 1];

            // Compute the step size
            double step_size = residual_norm / conjugate_direction;

            // Update the solver
            for (int i = 0; i < n_; i++) {
                solver_[i] -= step_size * matrix_[i * n_ + i];
            }

            // Compute the new residual norm
            residual_norm = 0;
            for (int i = 0; i < n_; i++) {
                residual_norm += matrix_[i * n_ + i] * solver_[i];
            }
            residual_norm /= matrix_[n_ * n_ - 1];
        }
    }

private:
    // Number of variables
    int n_;

    // Matrix and solver
    double* matrix_;
    double* solver_;
};
