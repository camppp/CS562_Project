#include <boost/multi/array.hpp>
#include <boost/mpi3/communicator.hpp>
#include <boost/mpi3/environment.hpp>
#include <iostream>
#include <random>

using namespace boost::multi;
using namespace boost::mpi3;

int main(int argc, char** argv) {
  // Initialize the MPI environment
  environment env(argc, argv);

  // Get the number of processes and the rank of this process
  int num_processes = env.size();
  int rank = env.rank();

  // Create a multi-dimensional array with dimensions 3x4x5
  array<double, 3> arr(3, 4, 5);

  // Populate the array with random values
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<double> dist(0.0, 1.0);
  for (int i = 0; i < arr.size(); i++) {
    arr[i] = dist(gen);
  }

  // Perform a specific operation on the array elements
  for (int i = 0; i < arr.size(); i++) {
    arr[i] = arr[i] * 2.0;
  }

  // Output the result of the operation
  if (rank == 0) {
    std::cout << "Result of operation: " << std::endl;
    for (int i = 0; i < arr.size(); i++) {
      std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
  }

  // Finalize the MPI environment
  env.finalize();

  return 0;
}
