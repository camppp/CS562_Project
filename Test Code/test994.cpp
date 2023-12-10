#include <hpx/hpx_init.hpp>
#include <hpx/hpx_finalize.hpp>
#include <hpx/include/iostream.hpp>
#include <hpx/include/parallel_algorithm.hpp>
#include <hpx/include/parallel_vector.hpp>

int hpx_main(int argc, char** argv)
{
    // Initialize the HPX runtime environment
    hpx::parallel::execution::parallel_executor exec;
    hpx::parallel::execution::parallel_executor exec2;

    // Create distributed vectors on all available localities
    hpx::parallel::vector<int> vec1(100, 0, exec);
    hpx::parallel::vector<int> vec2(100, 0, exec2);
    hpx::parallel::vector<int> result(100, 0, exec);

    // Populate the distributed vectors with random values
    std::srand(std::time(0));
    std::for_each(vec1.begin(), vec1.end(), [](int& val) { val = std::rand() % 100; });
    std::for_each(vec2.begin(), vec2.end(), [](int& val) { val = std::rand() % 100; });

    // Perform distributed addition of the vectors
    hpx::parallel::transform(exec, vec1.begin(), vec1.end(), vec2.begin(), result.begin(),
        [](int a, int b) { return a + b; });

    // Print the result of the addition
    hpx::cout << "Resultant vector after addition: ";
    for (int val : result)
    {
        hpx::cout << val << " ";
    }
    hpx::cout << hpx::endl;

    return hpx::finalize();
}

int main(int argc, char* argv[])
{
    // Initialize HPX runtime
    return hpx::init(argc, argv);
}
