#include <boost/multi_array.hpp>
#include <iostream>

int main() {
  // Create a two-dimensional multi_array with dimensions 3x3 and storage order set to row-major
  boost::multi_array<int, 2> arr(boost::extents[3][3]);

  // Initialize the multi_array with integer values from 1 to 9 in row-major order
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      arr[i][j] = i * 3 + j + 1;
    }
  }

  // Print the elements of the multi_array in row-major order
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      std::cout << arr[i][j] << " ";
    }
    std::cout << std::endl;
  }

  // Print the elements of the multi_array in column-major order
  for (int j = 0; j < 3; j++) {
    for (int i = 0; i < 3; i++) {
      std::cout << arr[i][j] << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
