template <template <typename...> class T, typename Tuple>
struct tuple_template_forward_t {
    using type = T<typename Tuple::value_type...>;
};
