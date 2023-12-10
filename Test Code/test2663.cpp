template<typename Callable, typename... Args>
class Functor {
public:
    // Constructor that takes a callable object and its arguments
    Functor(Callable&& callable, Args&&... args) : callable_(std::forward<Callable>(callable)), args_(std::forward<Args>(args)...) {}

    // Invoke the stored callable object with the stored arguments
    auto operator()() {
        return callable_(args_...);
    }

private:
    // The callable object and its arguments
    Callable callable_;
    std::tuple<Args...> args_;
};
