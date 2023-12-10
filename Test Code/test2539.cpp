#include <iostream>
#include <boost/mpi.hpp>
#include <boost/mpi/collectives.hpp>
#include <boost/multi_array.hpp>

namespace mpi = boost::mpi;

int main(int argc, char* argv[]) {
    mpi::environment env(argc, argv);
    mpi::communicator world;

    using array_type = boost::multi_array<double, 2>;
    array_type A(boost::extents[3][3], boost::fortran_storage_order());

    // Populate the array with random values
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            A[i][j] = static_cast<double>(i + j);
        }
    }

    // Perform an operation on the array elements (e.g., element-wise addition)
    mpi::broadcast(world, A.data(), A.num_elements(), 0);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            A[i][j] += world.rank();  // Each process adds its rank to the array elements
        }
    }

    // Output the result of the operation
    mpi::gather(world, A.data(), A.num_elements(), 0);
    if (world.rank() == 0) {
        std::cout << "Resulting array after parallel operation:" << std::endl;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                std::cout << A[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    return 0;
}
