#include <iostream>
#include <cmath>

std::pair<double, double> calculateParticlePosition(double vx, double vy, double vz, double xx, double zz, double rr, double th, double phi) {
    double xPrimAtZhit = vx + (zz - vz) * tan(th) * cos(phi);
    double yPrimAtZhit = vy + (zz - vz) * tan(th) * sin(phi);
    return std::make_pair(xPrimAtZhit, yPrimAtZhit);
}

int main() {
    // Example usage
    double vx = 1.0, vy = 2.0, vz = 3.0, xx = 4.0, zz = 5.0, rr = 6.0, th = 0.5, phi = 0.3;
    std::pair<double, double> position = calculateParticlePosition(vx, vy, vz, xx, zz, rr, th, phi);
    std::cout << "Particle position at time " << xx << ": (" << position.first << ", " << position.second << ")" << std::endl;
    return 0;
}
