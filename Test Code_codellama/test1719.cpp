#include <boost/optional.hpp>
#include <com/sun/star/beans/Optional.hpp>

template <typename T>
inline ::boost::optional<T> make_optional(T const& v)
{
    return ::boost::optional<T>(v);
}

template <typename T>
inline ::boost::optional<T> make_optional(::com::sun::star::beans::Optional<T> const& o)
{
    return ::boost::optional<T>(o.getValue());
}
