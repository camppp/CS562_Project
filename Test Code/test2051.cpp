#include <type_traits>

namespace Rider {
    namespace Faiz {
        // Define the disjunction meta-function
        template <typename... Args>
        struct disjunction : std::false_type {};

        template <typename T>
        struct disjunction<T> : T {};

        template <typename T, typename... Args>
        struct disjunction<T, Args...> : std::conditional<T::value, T, disjunction<Args...>>::type {};

        // Define the STATIC_REQUIRE macro
        #define STATIC_REQUIRE(expr) static_assert(expr, "Static assertion failed")

        // Test the disjunction meta-function using STATIC_REQUIRE
        using true_type = std::true_type;
        using false_type = std::false_type;

        STATIC_REQUIRE(disjunction<true_type, false_type>::value);
        STATIC_REQUIRE(disjunction<false_type, true_type, false_type>::value);
        STATIC_REQUIRE(!disjunction<false_type, false_type, false_type>::value);
}
}
