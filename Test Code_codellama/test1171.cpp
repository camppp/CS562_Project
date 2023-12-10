#include <sstream>

template <typename Stream, typename T>
struct is_streamable {
    static constexpr bool value = std::is_same_v<decltype(std::declval<Stream&>() << std::declval<T>()), Stream&>;
};
