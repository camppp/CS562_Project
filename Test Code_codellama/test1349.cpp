#include <type_traits>

template <typename T, std::size_t N>
auto testme(T&&) -> std::enable_if_t<N == 2, int> {
    return 0;
}

template <typename T, std::size_t N>
auto testme(T&&) -> std::enable_if_t<N != 2, int> {
    // This specialization is not callable
}
