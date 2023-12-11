#include <type_traits>

template <typename T>
struct remove_varargs;

template <typename T, typename... Args>
struct remove_varargs<T(Args...)> {
    using type = T(Args...);
};

template <typename T, typename... Args>
struct remove_varargs<T(Args..., ...)> {
    using type = T(Args...);
};

int main() {
    // Assert that remove_varargs<int(int, int)>::type is int(int)
    static_assert(std::is_same_v<remove_varargs<int(int, int)>::type, int(int)>);

    // Assert that remove_varargs<int(int, int, ...)>::type is int(int)
    static_assert(std::is_same_v<remove_varargs<int(int, int, ...)>::type, int(int)>);

    // Assert that remove_varargs<int(int, int, int, ...)>::type is int(int, int)
    static_assert(std::is_same_v<remove_varargs<int(int, int, int, ...)>::type, int(int, int)>);

    return 0;
}
