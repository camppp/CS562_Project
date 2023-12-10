#include <iostream>

class FibonacciFunctor {
public:
    FibonacciFunctor() {
        // Initialize the internal state of the functor
        a = 0;
        b = 1;
    }

    int operator()() {
        // Return the next Fibonacci number
        int result = a;
        a = b;
        b = a + b;
        return result;
    }

private:
    int a;
    int b;
};

int main() {
    FibonacciFunctor fib;
    std::cout << fib() << std::endl;  // Output: 0
    std::cout << fib() << std::endl;  // Output: 1
    std::cout << fib() << std::endl;  // Output: 1
    std::cout << fib() << std::endl;  // Output: 2
    std::cout << fib() << std::endl;  // Output: 3
    return 0;
}
