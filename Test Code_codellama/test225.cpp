template <typename T>
struct is_pointer {
    static constexpr bool value = false;
};

template <typename T>
struct is_pointer<T*> {
    static constexpr bool value = true;
};

template <typename T>
struct is_pointer<const T*> {
    static constexpr bool value = true;
};

template <typename T>
struct is_pointer<volatile T*> {
    static constexpr bool value = true;
};

template <typename T>
struct is_pointer<const volatile T*> {
    static constexpr bool value = true;
};
