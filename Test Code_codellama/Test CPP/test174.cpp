#include <cmath>

double calculatePolygonArea(int n, double r) {
    return r * r * sin(2 * M_PI / n) / 2;
}
