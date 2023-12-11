#include <cmath>

double slerp(double startAngle, double endAngle, double t) {
  // Handle wrapping around of angles
  if (endAngle - startAngle > M_PI) {
    endAngle -= 2 * M_PI;
  } else if (endAngle - startAngle < -M_PI) {
    endAngle += 2 * M_PI;
  }

  // Calculate the slerp-interpolated angle
  double angle = startAngle + t * (endAngle - startAngle);

  // Ensure the angle is between 0 and 2π
  if (angle < 0) {
    angle += 2 * M_PI;
  } else if (angle > 2 * M_PI) {
    angle -= 2 * M_PI;
  }

  return angle;
}
