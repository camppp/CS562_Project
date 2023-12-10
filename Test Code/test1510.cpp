#include <type_traits>
#include <limits>

template<typename T, template <typename...> class seq, typename... Ts>
struct Index;

template<typename T, template <typename...> class seq, typename... Ts>
struct Index<T, seq<Ts...>> : std::integral_constant<std::size_t, Index<T, seq<Ts...>, 0>::value> {};

template<typename T, template <typename...> class seq, typename... Ts>
struct Index<T, seq<Ts...>, std::size_t N> : std::integral_constant<std::size_t, std::numeric_limits<std::size_t>::max()> {};

template<typename T, template <typename...> class seq, typename... Ts, std::size_t N>
struct Index<T, seq<T, Ts...>, N> : std::integral_constant<std::size_t, N> {};

template<typename T, template <typename...> class seq, typename... Ts>
struct Contains : std::disjunction<std::is_same<T, Ts>...> {};
