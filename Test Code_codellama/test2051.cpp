template <typename... Ts>
struct disjunction;

template <typename T, typename... Ts>
struct disjunction<T, Ts...> {
    using type = typename disjunction<Ts...>::type;
};

template <typename T>
struct disjunction<T> {
    using type = T;
};
