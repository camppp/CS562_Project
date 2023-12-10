#include <iostream>
#include <vector>
#include <chrono>

// Matrix-vector multiplication function
void matVecMult(const std::vector<std::vector<double>>& matrix, const std::vector<double>& vector, std::vector<double>& result) {
  // Initialize the result vector
  result.resize(matrix.size());

  // Iterate over the rows of the matrix
  for (int i = 0; i < matrix.size(); i++) {
    // Initialize the dot product
    double dotProduct = 0;

    // Iterate over the columns of the matrix
    for (int j = 0; j < matrix[i].size(); j++) {
      // Calculate the dot product
      dotProduct += matrix[i][j] * vector[j];
    }

    // Store the result in the result vector
    result[i] = dotProduct;
  }
}

// Benchmarking function
void benchmark(const std::vector<std::vector<double>>& matrix, const std::vector<double>& vector, const int numIterations) {
  // Initialize the result vector
  std::vector<double> result(matrix.size());

  // Warm-up iteration
  matVecMult(matrix, vector, result);

  // Benchmarking iterations
  auto start = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < numIterations; i++) {
    matVecMult(matrix, vector, result);
  }
  auto end = std::chrono::high_resolution_clock::now();

  // Print the benchmarking results
  std::cout << "Benchmarking results: " << std::endl;
  std::cout << "  Matrix size: " << matrix.size() << std::endl;
  std::cout << "  Vector size: " << vector.size() << std::endl;
  std::cout << "  Number of iterations: " << numIterations << std::endl;
  std::cout << "  Time taken: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " microseconds" << std::endl;
}

int main() {
  // Define the matrix and vector sizes
  const int matrixSize = 1000;
  const int vectorSize = 1000;

  // Initialize the matrix and vector
  std::vector<std::vector<double>> matrix(matrixSize, std::vector<double>(matrixSize));
  std::vector<double> vector(vectorSize);

  // Fill the matrix and vector with random values
  for (int i = 0; i < matrixSize; i++) {
    for (int j = 0; j < matrixSize; j++) {
      matrix[i][j] = (double)rand() / RAND_MAX;
    }
  }
  for (int i = 0; i < vectorSize; i++) {
    vector[i] = (double)rand() / RAND_MAX;
  }

  // Benchmark the matrix-vector multiplication algorithm
  benchmark(matrix, vector, 1000);

  return 0;
}
