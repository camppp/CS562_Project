#include <type_traits>

template<typename...>
struct list {};

template<typename T, typename U>
struct less : std::integral_constant<bool, sizeof(T) < sizeof(U)> {};

template<typename...>
struct _merge_impl;

template<typename... xs>
struct _merge_impl<list<xs...>, list<>, list<xs...>, less>
{};

template<typename... ys>
struct _merge_impl<list<>, list<ys...>, list<ys...>, less>
{};

template<typename x, typename... xt, typename y, typename... yt, typename... zs, typename cmp>
struct _merge_impl<list<x, xt...>, list<y, yt...>, list<zs...>, cmp>
    : std::conditional_t<cmp::template apply<x, y>::value,
                        _merge_impl<list<xt...>, list<y, yt...>, list<zs..., x>, cmp>,
                        _merge_impl<list<x, xt...>, list<yt...>, list<zs..., y>, cmp>>
{};

int main() {
    using merged_list = _merge_impl<list<1, 3, 5>, list<2, 4, 6>, list<>, less>::type;
    // merged_list is now list<1, 2, 3, 4, 5, 6>
    return 0;
}
