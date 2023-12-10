#include <iostream>
#include <valarray>
#include <functional>

class function_compiler {
private:
    std::function<double(const std::valarray<double>&)> compiled_function;

public:
    function_compiler(std::function<double(const std::valarray<double>&)> func) : compiled_function(func) {}

    double execute(const std::valarray<double>& input) {
        if (input.size() == 0) {
            throw std::invalid_argument("Input array must not be empty");
        }
        return compiled_function(input);
    }
};

int main() {
    // Example usage
    function_compiler fn_c([](const std::valarray<double>& input) -> double { return input[0] * 2; });

    std::valarray<double> input_array = {3.14};
    try {
        double result = fn_c.execute(input_array);
        std::cout << "Result: " << result << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
