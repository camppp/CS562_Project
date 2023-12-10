c
void moveRobot(double *x, double *y, double *theta, double velocity, double yaw_rate, double delta_t) {
    // Compute the new x and y coordinates based on the motion model equations
    *x += velocity_div_yaw_rate * (sin(*theta + yaw_rate_times_delta_t) - sin(*theta));
    *y += velocity_div_yaw_rate * (cos(*theta) - cos(*theta + yaw_rate_times_delta_t));

    // Compute the new heading angle based on the yaw rate and time increment
    *theta += yaw_rate_times_delta_t;
}
