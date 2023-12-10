template<typename ReturnType, bool IsConst, ExternalFunctorObjectToBeCached CachePolicy>
class TaskType {
public:
    TaskType(const std::function<ReturnType()>& func) : func_(func) {}

    ReturnType execute() {
        if constexpr (CachePolicy == ExternalFunctorObjectToBeCached::yes) {
            if (result_ == nullptr) {
                result_ = func_();
            }
            return *result_;
        } else {
            return func_();
        }
    }

private:
    std::function<ReturnType()> func_;
    std::unique_ptr<ReturnType> result_;
};

template<typename ReturnType, typename Func>
TaskType<ReturnType, true, ExternalFunctorObjectToBeCached::no> make_TaskType(Func&& func) {
    return TaskType<ReturnType, true, ExternalFunctorObjectToBeCached::no>(std::forward<Func>(func));
}

template<typename T, typename Func>
TaskType<T, true, ExternalFunctorObjectToBeCached::no> make_TaskType(T&& t, Func&& func) {
    return TaskType<T, true, ExternalFunctorObjectToBeCached::no>(std::forward<T>(t), std::forward<Func>(func));
}
