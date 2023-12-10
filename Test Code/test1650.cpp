#include <type_traits>
#include <boost/type_traits.hpp>

template <typename T>
struct is_convertible_to_int : boost::mpl::and_<
    boost::mpl::not_<std::is_same<T, bool>>,
    boost::mpl::not_<std::is_same<T, char>>,
    boost::mpl::not_<std::is_same<T, unsigned char>>,
    boost::mpl::not_<std::is_same<T, signed char>>,
    boost::mpl::not_<std::is_same<T, wchar_t>>,
    boost::mpl::not_<std::is_same<T, char16_t>>,
    boost::mpl::not_<std::is_same<T, char32_t>>,
    boost::mpl::or_<
        boost::is_convertible<T, int>,
        boost::is_convertible<T, unsigned int>,
        boost::is_convertible<T, long>,
        boost::is_convertible<T, unsigned long>,
        boost::is_convertible<T, long long>,
        boost::is_convertible<T, unsigned long long>
    >
> {};
