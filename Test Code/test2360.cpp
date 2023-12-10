#include <iostream>
#include <utility>

template <typename Signature>
class function_ref;

template <typename R, typename... Args>
class function_ref<R(Args...)> {
public:
    function_ref() = delete;

    template <typename F>
    function_ref(F&& f) : erased_object(nullptr), erased_function(nullptr) {
        using function_type = R(*)(void*, Args...);
        erased_object = &f;
        erased_function = [](void* obj, Args... args) -> R {
            return (*reinterpret_cast<F*>(obj))(std::forward<Args>(args)...);
        };
    }

    R operator()(Args&&... args) const {
        return erased_function(erased_object, std::forward<Args>(args)...);
    }
};

// Example usage
int add(int a, int b) {
    return a + b;
}

int main() {
    function_ref<int(int, int)> add_ref = add;
    std::cout << add_ref(3, 4) << std::endl;  // Output: 7
    return 0;
}
