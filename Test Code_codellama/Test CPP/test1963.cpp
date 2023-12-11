#include <functional>
#include <valarray>

class function_compiler {
public:
    function_compiler(std::function<double(const std::valarray<double>&)> func)
        : func_(func) {}

    double operator()(const std::valarray<double>& x) {
        return func_(x);
    }

private:
    std::function<double(const std::valarray<double>&)> func_;
};
