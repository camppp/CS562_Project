#include <type_traits>

// Define the remove_varargs type trait
template <typename T>
struct remove_varargs;

// Specialization for member function pointer with variadic arguments
template <typename R, typename C, typename... Args>
struct remove_varargs<R(C::*)(Args..., ...) const volatile> {
    using type = R(C::*)(Args...);
};

// Define the CT_ASSERT macro
#define CT_ASSERT(expr) static_assert(expr, #expr)

// Usage of remove_varargs type trait and assertions
int main() {
    using va_cvr = void(BOOST_CLBL_TRTS_DEFAULT_VARARGS_CC foo::*)(int&, int&&, ...) const volatile RREF;

    CT_ASSERT(std::is_same<f,    typename remove_varargs<va_f>::type>{});
    CT_ASSERT(std::is_same<l,    typename remove_varargs<va_l>::type>{});
    CT_ASSERT(std::is_same<r,    typename remove_varargs<va_r>::type>{});
    CT_ASSERT(std::is_same<c,    typename remove_varargs<va_c>::type>{});
    CT_ASSERT(std::is_same<cl,   typename remove_varargs<va_cl>::type>{});
    CT_ASSERT(std::is_same<cr,   typename remove_varargs<va_cr>::type>{});

    return 0;
}
