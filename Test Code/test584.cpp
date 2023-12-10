// Define the Size meta-function
template <typename... Args>
struct Size {
    static constexpr std::size_t value = sizeof...(Args);
};

// Example usage
using P1 = std::tuple<int, double>;
static_assert(Size<P1>::value == 2);

#if ZEN_STL
// Additional code for ZEN_STL
#endif
