#include <iostream>
#include <cmath>

// Define the ODE system
void ode_system(double t, double y1, double y2, double *dy1, double *dy2) {
  *dy1 = -0.5 * y1;
  *dy2 = 0.5 * y1 - 0.2 * y2;
}

// Define the initial conditions
double y1_0 = 1;
double y2_0 = 0;

// Define the time step and total time
double dt = 0.01;
double t_end = 5;

// Define the output variables
double y1_out, y2_out;

// Define the Runge-Kutta-Cash-Karp method
void rkck(double t, double y1, double y2, double *dy1, double *dy2) {
  double k11 = dt * dy1;
  double k12 = dt * dy2;
  double k21 = dt * (dy1 + 0.5 * k11);
  double k22 = dt * (dy2 + 0.5 * k12);
  double k31 = dt * (dy1 + 0.5 * k21);
  double k32 = dt * (dy2 + 0.5 * k22);
  double k41 = dt * (dy1 + k31);
  double k42 = dt * (dy2 + k32);
  double k51 = dt * (dy1 + 0.5 * k41);
  double k52 = dt * (dy2 + 0.5 * k42);
  double k61 = dt * (dy1 + k51);
  double k62 = dt * (dy2 + k52);
  double y1_new = y1 + (k11 + 2 * k21 + 2 * k31 + k41) / 6;
  double y2_new = y2 + (k12 + 2 * k22 + 2 * k32 + k42) / 6;
  *dy1 = y1_new - y1;
  *dy2 = y2_new - y2;
}

int main() {
  // Initialize the output variables
  y1_out = y1_0;
  y2_out = y2_0;

  // Perform the integration
  for (double t = 0; t < t_end; t += dt) {
    // Evaluate the ODE system
    double dy1, dy2;
    ode_system(t, y1_out, y2_out, &dy1, &dy2);

    // Perform the Runge-Kutta-Cash-Karp method
    rkck(t, y1_out, y2_out, &dy1, &dy2);

    // Update the output variables
    y1_out += dy1;
    y2_out += dy2;

    // Print the output variables at regular intervals
    if (t % 0.1 == 0) {
      std::cout << "t = " << t << ", y1 = " << y1_out << ", y2 = " << y2_out << std::endl;
    }
  }

  return 0;
}
