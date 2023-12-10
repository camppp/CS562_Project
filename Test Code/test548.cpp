#include <iostream>
#include <boost/mpl/math/is_even.hpp>

int main() {
    int input;
    std::cout << "Enter an integer: ";
    std::cin >> input;

    if (boost::mpl::math::is_even(input)) {
        std::cout << "Even" << std::endl;
    } else {
        std::cout << "Odd" << std::endl;
    }

    return 0;
}
