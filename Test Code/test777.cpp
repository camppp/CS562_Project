#include <iostream>
#include <cmath>

// Define a 3D vector structure
struct Vector3
{
    double x, y, z;
};

// Define a 3D rectangle structure
struct Rectangle3
{
    Vector3 center;  // Center of the rectangle
    Vector3 axis[3]; // Axis directions of the rectangle
    double extent[3]; // Extents along each axis
};

// Function to calculate the shortest distance between a 3D point and a 3D rectangle
double distanceToRectangle(const Vector3& point, const Rectangle3& rectangle)
{
    Vector3 diff = {point.x - rectangle.center.x, point.y - rectangle.center.y, point.z - rectangle.center.z};
    double sqrDistance = 0.0;

    for (int i = 0; i < 3; ++i)
    {
        double projection = diff.x * rectangle.axis[i].x + diff.y * rectangle.axis[i].y + diff.z * rectangle.axis[i].z;
        if (projection < -rectangle.extent[i])
        {
            double delta = projection + rectangle.extent[i];
            sqrDistance += delta * delta;
            projection = -rectangle.extent[i];
        }
        else if (projection > rectangle.extent[i])
        {
            double delta = projection - rectangle.extent[i];
            sqrDistance += delta * delta;
            projection = rectangle.extent[i];
        }
        sqrDistance += projection * projection;
    }

    return std::sqrt(sqrDistance);
}

int main()
{
    // Example usage
    Vector3 point = {1.0, 2.0, 3.0};
    Rectangle3 rectangle = {{0.0, 0.0, 0.0}, {{1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 1.0}}, {2.0, 1.0, 3.0}};
    double shortestDistance = distanceToRectangle(point, rectangle);
    std::cout << "Shortest distance between the point and the rectangle: " << shortestDistance << std::endl;

    return 0;
}
