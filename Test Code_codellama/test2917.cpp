template<typename T>
struct is_array {
    static constexpr bool value = false;
};

template<typename T, size_t N>
struct is_array<T[N]> {
    static constexpr bool value = true;
};

template<typename T>
struct is_array<T[]> {
    static constexpr bool value = true;
};
