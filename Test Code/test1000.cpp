#include <cmath>

double slerp(double startAngle, double endAngle, double t) {
    const double PI = 3.14159265358979323846;
    double delta = endAngle - startAngle;
    if (delta > PI) {
        endAngle -= 2 * PI;
    } else if (delta < -PI) {
        endAngle += 2 * PI;
    }
    return startAngle + t * (endAngle - startAngle);
}
