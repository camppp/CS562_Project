namespace tdc {

template<class T, class X = void>
struct ConstIntegerBaseTrait {
    using BaseType = T;
};

template<class T>
struct ConstIntegerBaseTrait<T, std::enable_if_t<std::is_integral_v<T>>> {
    using BaseType = std::conditional_t<sizeof(T) <= sizeof(int), int,
        std::conditional_t<sizeof(T) <= sizeof(long), long,
            std::conditional_t<sizeof(T) <= sizeof(long long), long long, void>>>;
};

}  // namespace tdc
