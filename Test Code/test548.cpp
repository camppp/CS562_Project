#include <iostream>
#include <boost/mpl/math/is_even.hpp>

int main() {
    int num;
    std::cin >> num;

    if (boost::mpl::math::is_even<num>::value) {
        std::cout << "Even" << std::endl;
    } else {
        std::cout << "Odd" << std::endl;
    }

    return 0;
}
