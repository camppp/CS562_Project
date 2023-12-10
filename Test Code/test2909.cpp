#include <math.h>

float calculateDistance(float off_x, float off_y, float off_z, float POLY_cam_x, float POLY_cam_y, float POLY_cam_z) {
    float vx = off_x - POLY_cam_x;
    float vy = off_y - POLY_cam_y;
    float vz = off_z - POLY_cam_z;

    return sqrt(vx * vx + vy * vy + vz * vz);
}
