#include <type_traits>

namespace Tristeon {
    template <typename T>
    struct IsPointer : std::false_type {};

    template <typename T>
    struct IsPointer<T*> : std::true_type {};
}
