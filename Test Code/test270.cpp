#include <iostream>

template<typename... Types>
struct apply {
    static typename std::result_of<decltype(&Types::operator())(Types...)>::type result;

    template<typename F, typename... Args>
    static void apply(F&& f, Args&&... args) {
        result = std::forward<F>(f)(std::forward<Args>(args)...);
    }
};

int main() {
    // Example usage
    apply<int, int>::apply(add, 3, 4);
    std::cout << apply<int, int>::result << std::endl;  // Output: 7
    return 0;
}
