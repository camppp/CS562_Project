template<typename...>
struct _merge_impl;

template<typename... xs, typename... ys, typename... zs, typename cmp>
struct _merge_impl<list<xs...>, list<ys...>, list<zs...>, cmp>
{
    using type = list<zs..., xs..., ys...>;
};
