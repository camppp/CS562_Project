#include <boost/type_traits.hpp>

template <typename T>
struct is_convertible_to_int
{
    using type = boost::is_convertible<T, int>;
};

static_assert(is_convertible_to_int<float>::value, "Float should be convertible to int");
static_assert(!is_convertible_to_int<std::string>::value, "String should not be convertible to int");
