template<typename Func, typename... Args>
class apply {
public:
    using result_type = decltype(std::declval<Func>()(std::declval<Args>()...));
    result_type result;

    apply(Func func, Args... args) : result(func(args...)) {}

    result_type apply(Func func, Args... args) {
        return func(args...);
    }
};
