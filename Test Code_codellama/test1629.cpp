#include <iostream>
#include <array>

template <typename T, size_t size>
struct intern::TransformReduce_ {
    static T reduce(const std::array<T, size>& input1, const std::array<T, size>& input2,
                    const std::function<T(T, T)>& transformer, const std::function<T(T, T)>& reducer) {
        T result = transformer(input1[0], input2[0]);
        for (size_t i = 1; i < size; i++) {
            result = reducer(result, transformer(input1[i], input2[i]));
        }
        return result;
    }
};

template <typename T, size_t size>
T transform_reduce(const std::array<T, size>& input1, const std::array<T, size>& input2,
                   const std::function<T(T, T)>& transformer, const std::function<T(T, T)>& reducer) {
    return intern::TransformReduce_<T, size>::reduce(input1, input2, transformer, reducer);
}

int main() {
    std::array<int, 5> input1 = {1, 2, 3, 4, 5};
    std::array<int, 5> input2 = {6, 7, 8, 9, 10};

    auto result = transform_reduce(input1, input2,
                                   [](int a, int b) { return a + b; },
                                   [](int a, int b) { return a * b; });

    std::cout << "Result: " << result << std::endl;

    return 0;
}
