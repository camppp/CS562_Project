#include <math.h>

double SignAzimuthDifference(double radCrs, double tanCrs) {
    double diff = fmod((tanCrs - radCrs + 2 * M_PI), (2 * M_PI));
    if (diff > M_PI) {
        diff -= 2 * M_PI;
    }
    return diff;
}

int main() {
    // Sample usage
    double radCrs = 1.2;  // Current heading
    double tanCrs = 0.8;  // Desired heading

    double diff = SignAzimuthDifference(radCrs, tanCrs);
    double dErr = fabs(diff) - M_PI_2;
    double c = 0;  // Initial value of c
    c = c + dErr;
    int k = 0;  // Initial value of k
    k++;

    return 0;
}
