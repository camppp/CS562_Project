#include <boost/test/data/monomorphic/grid.hpp>
#include <iostream>

int main() {
    // Define a 2D grid of integers with dimensions 3x3
    int data[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    // Create a boost grid using the 2D array
    boost::unit_test::data::monomorphic::grid<int, 2> grid(boost::extents[3][3] = data);

    // Iterate over the grid and calculate the sum of all elements
    int sum = 0;
    for (auto it = grid.begin(); it != grid.end(); ++it) {
        sum += *it;
    }

    // Output the calculated sum
    std::cout << "Sum of elements in the grid: " << sum << std::endl;

    return 0;
}
