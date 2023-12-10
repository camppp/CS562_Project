#include <boost/test/data/monomorphic/grid.hpp>

int main() {
    // Define a 2D grid of integers with dimensions 3x3
    boost::test::data::monomorphic::grid<int, 3, 3> grid;

    // Populate the grid with integer values from 1 to 9 in row-major order
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            grid(i, j) = i * 3 + j + 1;
        }
    }

    // Iterate over the grid and calculate the sum of all the elements
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            sum += grid(i, j);
        }
    }

    // Output the calculated sum of the elements in the grid
    std::cout << "Sum of elements in grid: " << sum << std::endl;

    return 0;
}
