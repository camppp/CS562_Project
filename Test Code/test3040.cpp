#include <iostream>
#include <type_traits>
#include "test_structs.hpp"
#include <boost/tti/has_data.hpp>

// Define the has_member_AnInt meta-function using Boost libraries
BOOST_TTI_HAS_DATA(AnInt)

template <typename T>
struct has_member_AnInt : boost::tti::has_data_AnInt<T> {};

int main() {
    std::cout << has_member_AnInt<HasAnInt>::value << std::endl;  // Should print 1 (true)
    std::cout << has_member_AnInt<NoAnInt>::value << std::endl;  // Should print 0 (false)
    return 0;
}
