template <typename Signature>
class function_ref {
public:
    template <typename F>
    function_ref(F&& f) : erased_object(f), erased_function(f) {}

    R operator()(Args&&... args) const {
        return erased_function(std::forward<Args>(args)...);
    }

private:
    void* erased_object;
    R(*erased_function)(Args...);
};
