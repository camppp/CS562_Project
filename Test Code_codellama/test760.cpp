#include <type_traits>

namespace eop {
    template <class _Tp, class U>
    struct is_nothrow_convertible_v {
        static constexpr bool value = std::is_nothrow_constructible_v<_Tp, U> &&
                                      std::is_nothrow_assignable_v<_Tp&, U> &&
                                      std::is_nothrow_convertible_v<_Tp, U>;
    };
}

template <class _Tp, class U>
inline constexpr bool linear_usable_as_v = eop::is_nothrow_convertible_v<_Tp, U>::value;
