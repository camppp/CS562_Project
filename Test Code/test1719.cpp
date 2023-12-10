// Include necessary headers
#include <boost/optional.hpp>
#include <com/sun/star/beans/Optional.hpp>

// Define the make_optional function for regular values
template <typename T>
inline ::boost::optional<T> make_optional( T const& v )
{
    return ::boost::optional<T>(v);
}

// Define the make_optional function for com::sun::star::beans::Optional objects
template <typename T>
inline ::boost::optional<T> make_optional(
    ::com::sun::star::beans::Optional<T> const& o )
{
    if (o.is()) {
        return ::boost::optional<T>(o.get());
    } else {
        return ::boost::optional<T>();
    }
}
