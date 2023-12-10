#include <type_traits>

// Define the concept IsArgumentProviderOfExpandables
template <typename T>
concept IsArgumentProviderOfExpandables = requires(T t) {
    // Check if T has a member function expand() that returns a sequence of arguments
    { t.expand() } -> std::convertible_to<std::tuple<>>;  // Check if expand() returns a tuple or equivalent

    // Additional check for variable length sequence of arguments
    { std::tuple_size<decltype(t.expand())>::value } -> std::integral;  // Check if the size of the returned tuple is integral
};
