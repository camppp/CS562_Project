#include <iostream>
#include <spla-cpp/spla-cpp.h>

int main() {
  // Initialize two matrices with the appropriate dimensions and values
  spla::Matrix<double> matrixA(2, 3, {1, 2, 3, 4, 5, 6});
  spla::Matrix<double> matrixB(3, 2, {7, 8, 9, 10, 11, 12});

  // Perform a matrix-matrix multiplication using the spla-cpp library
  spla::Matrix<double> resultMatrix = matrixA * matrixB;

  // Print the contents of the result matrix to the console
  std::cout << "Result matrix: " << std::endl;
  std::cout << resultMatrix << std::endl;

  return 0;
}
