#include <iostream>
#include <memory>
#include <vector>
#include <complex>
#include <gko/gko.hpp>

void nonlinear_step(std::shared_ptr<const DefaultExecutor> exec, int n,
                    double nonlinear_scale, double potential_scale,
                    double time_scale,
                    const gko::matrix::Dense<double>* potential,
                    gko::matrix::Dense<std::complex<double>>* ampl) {
    // Compute the nonlinear step operation
    run_kernel(exec, [=] __device__(int i, int j) {
        // Compute the nonlinear term
        double nonlinear_term = nonlinear_scale * potential_scale * potential->at(i, j) * time_scale;

        // Compute the amplitude
        std::complex<double> amplitude = ampl->at(i, j) + nonlinear_term;

        // Store the amplitude
        ampl->at(i, j) = amplitude;
    });
}
