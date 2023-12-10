c
#include <math.h>

double SignAzimuthDifference(double radCrs, double tanCrs) {
    double diff = fabs(radCrs - tanCrs);
    if (diff > M_PI_2) {
        diff = diff - M_PI_2;
    }
    return diff;
}
