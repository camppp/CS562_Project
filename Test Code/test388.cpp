#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <random>

// Structure to represent a 2D point
struct Point {
    double x;
    double y;
};

// Function to calculate the distance between a point and a line
double distanceToLine(const Point& point, double slope, double intercept) {
    return std::abs(slope * point.x - point.y + intercept) / std::sqrt(slope * slope + 1);
}

// RANSAC algorithm to fit a line to 2D points
std::pair<double, double> ransacLineFitting(const std::vector<Point>& points, int iterations, double inlierThreshold) {
    std::pair<double, double> bestModel;  // Parameters of the best-fitting line model
    int bestInlierCount = 0;  // Number of inliers for the best model

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(0, points.size() - 1);

    for (int i = 0; i < iterations; ++i) {
        // Randomly sample two points
        int index1 = distribution(gen);
        int index2 = distribution(gen);
        while (index2 == index1) {
            index2 = distribution(gen);
        }

        // Fit a line to the sampled points (y = mx + c)
        double x1 = points[index1].x;
        double y1 = points[index1].y;
        double x2 = points[index2].x;
        double y2 = points[index2].y;

        double slope = (y2 - y1) / (x2 - x1);
        double intercept = y1 - slope * x1;

        // Count inliers for this model
        int inlierCount = 0;
        for (const auto& point : points) {
            double distance = distanceToLine(point, slope, intercept);
            if (distance < inlierThreshold) {
                inlierCount++;
            }
        }

        // Update the best model if this model has more inliers
        if (inlierCount > bestInlierCount) {
            bestInlierCount = inlierCount;
            bestModel = std::make_pair(slope, intercept);
        }
    }

    return bestModel;
}

int main() {
    // Example usage
    std::vector<Point> points = {{1.0, 2.0}, {2.0, 3.0}, {3.0, 4.0}, {4.0, 5.0}, {5.0, 6.0}};
    int iterations = 1000;
    double inlierThreshold = 0.5;

    std::pair<double, double> bestModel = ransacLineFitting(points, iterations, inlierThreshold);
    std::cout << "Best-fitting line: y = " << bestModel.first << "x + " << bestModel.second << std::endl;

    return 0;
}
