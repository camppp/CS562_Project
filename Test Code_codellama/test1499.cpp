#include <cmath>

std::pair<double, double> calculateParticlePosition(double vx, double vy, double vz, double xx, double zz, double rr, double th, double phi) {
    double xPrimAtZhit = vx + (zz - vz) * tan(th) * cos(phi);
    double yPrimAtZhit = vy + (zz - vz) * tan(th) * sin(phi);
    double x = xPrimAtZhit + rr * cos(xx);
    double y = yPrimAtZhit + rr * sin(xx);
    return {x, y};
}
