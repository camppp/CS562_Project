#include <boost/multiprecision/cpp_dec_float.hpp>

template <typename PrecisionType, typename ExpressionTemplateOption>
class CustomPrecisionArithmetic {
public:
    using precision_type = PrecisionType;
    using expression_template_option = ExpressionTemplateOption;

    CustomPrecisionArithmetic(const precision_type& precision, const expression_template_option& et_option)
        : precision_(precision), et_option_(et_option) {}

    precision_type addition(const precision_type& num1, const precision_type& num2) {
        return num1 + num2;
    }

    precision_type subtraction(const precision_type& num1, const precision_type& num2) {
        return num1 - num2;
    }

    precision_type multiplication(const precision_type& num1, const precision_type& num2) {
        return num1 * num2;
    }

    precision_type division(const precision_type& num1, const precision_type& num2) {
        return num1 / num2;
    }

private:
    precision_type precision_;
    expression_template_option et_option_;
};

int main() {
    using custom_precision = boost::multiprecision::cpp_dec_float<1024>;
    using et_off_option = boost::multiprecision::expression_template_option::et_off;

    CustomPrecisionArithmetic<custom_precision, et_off_option> custom_arithmetic(custom_precision(10), et_off_option());

    custom_precision num1 = 123.456;
    custom_precision num2 = 789.012;

    custom_precision sum = custom_arithmetic.addition(num1, num2);
    custom_precision difference = custom_arithmetic.subtraction(num1, num2);
    custom_precision product = custom_arithmetic.multiplication(num1, num2);
    custom_precision quotient = custom_arithmetic.division(num1, num2);

    // Perform operations with the specified precision and expression template option
    // ...

    return 0;
}
