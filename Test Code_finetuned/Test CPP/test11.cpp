#include "base.h"
#include "cords.h"
#include "align_util.h"
#include <math.h>

double calculateDistance(Point p1, Point p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt(dx*dx + dy*dy);
}