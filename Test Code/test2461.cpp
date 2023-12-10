#include <iostream>
#include <tuple>

namespace emp {
    // Function to apply a tuple of arguments to a given function and return the result
    template <typename Func, typename Tuple, std::size_t... I>
    decltype(auto) ApplyTupleHelper(Func&& func, Tuple&& args, std::index_sequence<I...>) {
        return std::forward<Func>(func)(std::get<I>(std::forward<Tuple>(args))...);
    }

    template <typename Func, typename... Args>
    decltype(auto) ApplyTuple(Func&& func, const std::tuple<Args...>& args) {
        return ApplyTupleHelper(std::forward<Func>(func), args, std::index_sequence_for<Args...>{});
    }
}

// Function to calculate the sum of three input arguments
int Sum3(int a, int b, int c) {
    return a + b + c;
}

// Function to calculate the product of three input arguments
int Prod3(int a, int b, int c) {
    return a * b * c;
}

int main() {
    std::cout << "\nApplyTuple results...:\n";
    int x = 10;
    int y = 13;
    int z = 22;
    auto test_tup = std::make_tuple(x, y, z);
    std::cout << "Sum3(" << x << "," << y << "," << z << ") = "
        << emp::ApplyTuple(Sum3, test_tup) << std::endl;
    std::cout << "Prod3(" << x << "," << y << "," << z << ") = "
        << emp::ApplyTuple(Prod3, test_tup) << std::endl;

    return 0;
}
