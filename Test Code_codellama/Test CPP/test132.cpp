#include <cmath>

string circleRelationship(double x1, double y1, double r1, double x2, double y2, double r2) {
    // Calculate the distance between the centers of the two circles
    double dx = x2 - x1;
    double dy = y2 - y1;
    double distance = sqrt(dx * dx + dy * dy);

    // Check if the circles are identical
    if (r1 == r2 && distance == 0) {
        return "More";
    }

    // Check if one circle is completely inside the other
    if (r1 < r2 && distance + r1 <= r2 || r2 < r1 && distance + r2 <= r1) {
        return "One";
    }

    // Check if the circles intersect
    if (distance <= r1 + r2) {
        return "One";
    }

    // Otherwise, the circles do not intersect
    return "None";
}
