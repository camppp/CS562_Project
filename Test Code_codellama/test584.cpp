#include <tuple>

template<typename... Ts>
struct Size {
    static constexpr std::size_t value = std::tuple_size<std::tuple<Ts...>>::value;
};

#if ZEN_STL
// Additional code for ZEN_STL
#endif

int main() {
    static_assert(Size<int, double>::value == 2);
    return 0;
}
