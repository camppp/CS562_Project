#include <iostream>
#include <boost/multi_array.hpp>

int main() {
    // Define the dimensions of the multi_array
    const int rows = 3;
    const int cols = 3;

    // Create a two-dimensional multi_array with row-major storage order
    typedef boost::multi_array<int, 2> array_type;
    array_type multi_arr(boost::extents[rows][cols], boost::multi_array_types::row_major);

    // Initialize the multi_array with integer values from 1 to 9 in row-major order
    int value = 1;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            multi_arr[i][j] = value++;
        }
    }

    // Print the elements of the multi_array in row-major order
    std::cout << "Row-major order:" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << multi_arr[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Print the elements of the multi_array in column-major order
    std::cout << "Column-major order:" << std::endl;
    for (int j = 0; j < cols; ++j) {
        for (int i = 0; i < rows; ++i) {
            std::cout << multi_arr[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
