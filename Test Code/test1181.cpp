#include <math.h>

void moveRobot(double *x, double *y, double *theta, double velocity, double yaw_rate, double delta_t) {
    double velocity_div_yaw_rate = velocity / yaw_rate;
    *x += velocity_div_yaw_rate * (sin(*theta + yaw_rate * delta_t) - sin(*theta));
    *y += velocity_div_yaw_rate * (cos(*theta) - cos(*theta + yaw_rate * delta_t));
    *theta += yaw_rate * delta_t;
}
