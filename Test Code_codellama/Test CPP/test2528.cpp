template <typename Component, typename Context, typename Iterator>
struct end_director_base {
    // ...

    template <typename Component, typename Context, typename Iterator>
    struct attribute {
        using type = typename Component::attribute_type;
    };
};
