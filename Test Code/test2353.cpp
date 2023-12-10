#include <tuple>

template <template <typename...> class T, typename Tuple>
struct tuple_template_forward_t;

template <template <typename...> class T, typename... Args>
struct tuple_template_forward_t<T, std::tuple<Args...>> {
    using type = T<Args...>;
};

// Test the implementation
static_assert(std::is_same<tuple_template_forward_t<std::tuple, std::tuple<int, int, float>>::type, std::tuple<int, int, float>>::value, "t1 != t2");
static_assert(std::is_same<tuple_template_forward_t<std::tuple, std::tuple<float, int, double>>::type, std::tuple<float, int, double>>::value, "t3 != t4");
