#include <iostream>
#include <vector>
#include <set>
using namespace std;

class ColoredBalls {
private:
    vector<vector<int>> balls;  // Store the balls as (position, color) pairs
    set<int> distinctColors;    // Store the distinct colors

public:
    ColoredBalls(int n) {
        balls.resize(n + 1);
    }

    void addBall(int x, int c) {
        balls[x].push_back(c);  // Add the color to the position x
        distinctColors.insert(c);  // Update the set of distinct colors
    }

    int queryDistinctColors(int l, int r) {
        set<int> colorsInRange;  // Store the distinct colors within the range [l, r]

        for (int i = l; i <= r; i++) {
            for (int color : balls[i]) {
                colorsInRange.insert(color);  // Add the colors within the range to the set
            }
        }

        return colorsInRange.size();  // Return the number of distinct colors within the range
    }
};

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    ColoredBalls coloredBalls(n);

    // Example usage:
    coloredBalls.addBall(1, 3);  // Add a ball at position 1 with color 3
    coloredBalls.addBall(2, 5);  // Add a ball at position 2 with color 5
    coloredBalls.addBall(3, 3);  // Add a ball at position 3 with color 3

    int distinctColorsInRange = coloredBalls.queryDistinctColors(1, 3);  // Query the distinct colors within the range [1, 3]
    cout << "Distinct colors in range: " << distinctColorsInRange << endl;

    return 0;
}
