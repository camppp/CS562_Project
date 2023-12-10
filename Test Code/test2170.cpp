#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Define the structure to represent an obstacle
struct Obstacle {
    double x, y, z;
};

// Define the structure to represent an ellipsoid
struct Ellipsoid {
    double radius_x, radius_y, radius_z;
    double orientation_x, orientation_y, orientation_z;
};

// Function to find the closest obstacle to an ellipsoid
Obstacle closest_obstacle(const Ellipsoid& ellipsoid, const vector<Obstacle>& obstacles) {
    double min_distance = INFINITY;
    Obstacle closest_obstacle;

    for (const auto& obstacle : obstacles) {
        // Calculate the distance between the ellipsoid and the obstacle
        double distance = sqrt(pow(obstacle.x - ellipsoid.x, 2) + pow(obstacle.y - ellipsoid.y, 2) + pow(obstacle.z - ellipsoid.z, 2));

        // If the distance is less than the current minimum distance, update the closest obstacle
        if (distance < min_distance) {
            min_distance = distance;
            closest_obstacle = obstacle;
        }
    }

    return closest_obstacle;
}

int main() {
    // Define the ellipsoid parameters
    Ellipsoid ellipsoid;
    ellipsoid.radius_x = 1.0;
    ellipsoid.radius_y = 1.0;
    ellipsoid.radius_z = 1.0;
    ellipsoid.orientation_x = 0.0;
    ellipsoid.orientation_y = 0.0;
    ellipsoid.orientation_z = 0.0;

    // Define the set of obstacles
    vector<Obstacle> obstacles;
    obstacles.push_back({0.0, 0.0, 0.0});
    obstacles.push_back({1.0, 0.0, 0.0});
    obstacles.push_back({0.0, 1.0, 0.0});
    obstacles.push_back({0.0, 0.0, 1.0});

    // Find the closest obstacle to the ellipsoid
    Obstacle closest_obstacle = closest_obstacle(ellipsoid, obstacles);

    // Print the closest obstacle
    cout << "Closest obstacle: (" << closest_obstacle.x << ", " << closest_obstacle.y << ", " << closest_obstacle.z << ")" << endl;

    return 0;
}
