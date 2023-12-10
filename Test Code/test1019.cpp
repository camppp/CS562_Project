#include <type_traits>

enum class ExternalFunctorObjectToBeCached { yes, no };

template <typename ReturnType, bool IsConst, ExternalFunctorObjectToBeCached CachePolicy, class Func>
class TaskType {
public:
    ReturnType execute() {
        return func_();
    }

private:
    Func func_;
};

template <class Func>
constexpr auto make_TaskType() {
    return TaskType<std::invoke_result_t<Func>, true, ExternalFunctorObjectToBeCached::no, Func>();
}

template <typename T, std::conditional_t<std::is_class<T>::value, T&, T> val, class Func>
constexpr auto make_TaskType(Func&& func) {
    return TaskType<T, std::is_const<T>::value, ExternalFunctorObjectToBeCached::no, Func>(std::forward<Func>(func));
}
