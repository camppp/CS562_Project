#include <boost/range/algorithm.hpp>

namespace custom_range_test
{
    // Custom range testing function using Boost library
    template <typename Range>
    bool test_range(const Range& values)
    {
        boost::range_test_function::true_predicate predicate;
        return boost::all_of(values, predicate);
    }
}
