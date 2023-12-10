#include <type_traits>

namespace traits {
    template <typename T>
    struct is_string : std::false_type {};

    template <>
    struct is_string<std::string> : std::true_type {};

    template <>
    struct is_string<const char*> : std::true_type {};

    template <>
    struct is_string<char*> : std::true_type {};
}

template <typename T>
using enable_if_is_directly_serializable_t = std::enable_if_t<traits::is_string<T>::value || std::is_fundamental<T>::value>;
