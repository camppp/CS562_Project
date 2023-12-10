#include <iostream>
#include <boost/safe_float.hpp>
#include <boost/safe_float/convenience.hpp>
#include <boost/safe_float/policy/check_addition_overflow.hpp>
#include <boost/safe_float/policy/check_addition_underflow.hpp>
#include <boost/safe_float/policy/check_addition_inexact.hpp>
#include <boost/safe_float/policy/check_addition_invalid_result.hpp>

template <typename FloatingPointType>
class SafeFloat {
public:
    using SafeFloatType = boost::safe_float::safe_float<FloatingPointType>;

    SafeFloat(FloatingPointType value) : value_(value) {}

    SafeFloatType add(const SafeFloatType& other) {
        SafeFloatType result = value_ + other;
        return result;
    }

    void printErrorFlags(const SafeFloatType& result) {
        std::cout << "Overflow: " << result.error().overflow() << std::endl;
        std::cout << "Underflow: " << result.error().underflow() << std::endl;
        std::cout << "Inexact: " << result.error().inexact() << std::endl;
        std::cout << "Invalid Result: " << result.error().invalid_result() << std::endl;
    }

private:
    SafeFloatType value_;
};

int main() {
    SafeFloat<float> sf1(1.0f);
    SafeFloat<float> sf2(2.0f);

    // Adding with overflow and inexact checks
    SafeFloat<float>::SafeFloatType result1 = sf1.add(sf2, boost::safe_float::policy::check_addition_overflow{}, boost::safe_float::policy::check_addition_inexact{});
    sf1.printErrorFlags(result1);

    // Adding with underflow and invalid result checks
    SafeFloat<float>::SafeFloatType result2 = sf1.add(sf2, boost::safe_float::policy::check_addition_underflow{}, boost::safe_float::policy::check_addition_invalid_result{});
    sf1.printErrorFlags(result2);

    return 0;
}
