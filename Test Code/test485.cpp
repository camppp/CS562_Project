#include <iostream>
#include <boost/numeric/odeint.hpp>

typedef std::array<double, 2> state_type;

void ode_system(const state_type &y, state_type &dydt, const double t) {
    dydt[0] = -0.5 * y[0];
    dydt[1] = 0.5 * y[0] - 0.2 * y[1];
}

int main() {
    // Define the initial conditions
    state_type y = {1.0, 0.0};

    // Define the time span for integration
    double t_start = 0.0;
    double t_end = 5.0;
    double dt = 0.1;  // Output interval

    // Initialize the Runge-Kutta-Cash-Karp stepper
    boost::numeric::odeint::runge_kutta_cash_karp54<state_type> rk45;

    // Perform the integration
    for (double t = t_start; t <= t_end; t += dt) {
        std::cout << "t = " << t << ", y1 = " << y[0] << ", y2 = " << y[1] << std::endl;
        boost::numeric::odeint::integrate_adaptive(rk45, ode_system, y, t, t + dt, dt);
    }

    return 0;
}
