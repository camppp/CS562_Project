#include "context_setup.hpp"

namespace bc = boost::compute;

BOOST_AUTO_TEST_CASE(partial_sum_int)
{
    int data[] = { 1, 2, 5, 3, 9, 1, 4, 2 };
    bc::vector<int> a(8, context);
    bc::copy(data, data + 8, a.begin(), queue);

    bc::vector<int> b(a.size(), context);

    // Calculate the partial sum using parallel computation
    bc::exclusive_scan(a.begin(), a.end(), b.begin(), queue);

    // Verify the result by copying the data back to the host
    std::vector<int> result(a.size());
    bc::copy(b.begin(), b.end(), result.begin(), queue);

    // Print the partial sum result
    std::cout << "Partial Sum: ";
    for (const auto &val : result) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}
