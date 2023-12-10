#include <iostream>
#include <utility>

// Aspect class template
template <typename Function, typename... Args>
class Aspect {
public:
    Aspect(Function&& func) : func(std::forward<Function>(func)) {}

    template <typename... AOP>
    void invoke(Args&&... args, AOP...) {
        // Apply aspects here
        std::cout << "Before invoking function" << std::endl;
        func(std::forward<Args>(args)...);
        std::cout << "After invoking function" << std::endl;
    }

private:
    Function func;
};

// aopInvoke function template
template <typename... AOP, typename Function, typename... Args>
void aopInvoke(Function&& func, Args&&... args) {
    Aspect<Function, Args...> asp(std::forward<Function>(func));
    asp.invoke(std::forward<Args>(args)..., identity_t<AOP>()...);
}

// Example usage
void myFunction(int x, int y) {
    std::cout << "Inside myFunction: " << x + y << std::endl;
}

struct LoggingAspect {};
struct SecurityAspect {};

int main() {
    aopInvoke<LoggingAspect, SecurityAspect>(myFunction, 3, 4);
    return 0;
}
