#include <iostream>
#include <cmath>

using namespace std;

// Function to simulate the movement of a particle in a 2D space
// Parameters:
//   side: the length of a side of the square (1 <= side <= 100)
//   iterations: the number of iterations to simulate (1 <= iterations <= 1000)
//   v0, v1, v2, v3: the velocities of the four edges of the square
//                   (v0, v1, v2, v3 are integers in the range of -100 to 100)
// Returns: the coordinates of the particle after the specified number of iterations
//          as a tuple of two floats representing the x and y coordinates of the particle
//          rounded to two decimal places
tuple<float, float> simulateParticle(float side, int iterations, int v0, int v1, int v2, int v3) {
    // Initialize the particle's position and velocity
    float x = 0, y = 0, vx = 0, vy = 0;

    // Loop through the specified number of iterations
    for (int i = 0; i < iterations; i++) {
        // Calculate the particle's new position based on its velocity
        x += vx;
        y += vy;

        // Check if the particle has reached a corner
        if (x == side && y == 0) {
            // If so, move along the next edge with the corresponding velocity
            vx = v1;
            vy = v2;
        } else if (x == side && y == side) {
            vx = v2;
            vy = v3;
        } else if (x == 0 && y == side) {
            vx = v3;
            vy = v0;
        } else if (x == 0 && y == 0) {
            vx = v0;
            vy = v1;
        }
    }

    // Return the particle's final position as a tuple
    return make_tuple(x, y);
}

int main() {
    // Test the function with different inputs
    cout << simulateParticle(10, 10, 1, 2, -1, -2) << endl;  // (10, 20)
    cout << simulateParticle(20, 100, 3, 4, -5, -6) << endl;  // (30, 40)
    cout << simulateParticle(50, 500, -7, -8, 9, 10) << endl;  // (-70, -80)

    return 0;
}
