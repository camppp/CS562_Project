template<typename F, typename... Args>
class Aspect {
public:
    Aspect(F f) : f_(f) {}

    template<typename... Aspects>
    auto invoke(Args&&... args, Aspects&&... aspects) {
        // Apply aspects to the function invocation
        // ...
        return f_(std::forward<Args>(args)...);
    }

private:
    F f_;
};

template<typename F, typename... Args, typename... Aspects>
auto aopInvoke(F f, Args&&... args, Aspects&&... aspects) {
    Aspect<F, Args...> aspect(f);
    return aspect.invoke(std::forward<Args>(args)..., std::forward<Aspects>(aspects)...);
}
