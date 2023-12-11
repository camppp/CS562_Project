template<typename T>
struct value_of {
    using type = typename T::value_type;
};

template<typename T>
struct value_of<T*> {
    using type = typename std::remove_pointer<T>::type;
};

template<typename T>
struct value_of<std::vector<T>> {
    using type = T;
};
