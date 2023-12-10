#include <iostream>
#include <functional>

template<typename FunctorT>
class Functor
{
public:
    Functor(FunctorT functor) : functor_(functor) {}

    template<typename... Args>
    void operator()(Args... args) {
        functor_(args...);
    }

private:
    FunctorT functor_;
};

// Example usage
void simpleFunction() {
    std::cout << "Simple function called" << std::endl;
}

struct FunctorExample {
    void operator()(int x, int y) {
        std::cout << "Functor called with arguments: " << x << " and " << y << std::endl;
    }
};

int main() {
    // Wrap a simple function
    Functor<void(*)()> simpleFunctor(simpleFunction);
    simpleFunctor();

    // Wrap a functor
    Functor<FunctorExample> functorExample(FunctorExample());
    functorExample(10, 20);

    // Wrap a lambda
    auto lambda = [](int a, int b) {
        std::cout << "Lambda called with arguments: " << a << " and " << b << std::endl;
    };
    Functor<decltype(lambda)> lambdaFunctor(lambda);
    lambdaFunctor(5, 15);

    return 0;
}
