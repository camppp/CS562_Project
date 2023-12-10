#ifndef G6_NET_IO_CPO_HPP_
#define G6_NET_IO_CPO_HPP_

#include <type_traits>

namespace g6::io {

template <typename T, template <typename...> class Template>
struct is_specialization_of : std::false_type {};

template <typename... Ts, template <typename...> class Template>
struct is_specialization_of<Template<Ts...>, Template> : std::true_type {};

// Example usage:
// static_assert(is_specialization_of<std::vector<int>, std::vector>::value, "Error: Not a specialization of std::vector");
// static_assert(!is_specialization_of<int, std::vector>::value, "Error: Should not be a specialization of std::vector");

}// namespace g6::io

#endif// G6_NET_IO_CPO_HPP_
