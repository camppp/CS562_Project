#include <boost/safe_float.hpp>

class SafeFloat {
public:
    SafeFloat(float value) : value_(value) {}
    SafeFloat(double value) : value_(value) {}
    SafeFloat(long double value) : value_(value) {}

    SafeFloat& operator+=(const SafeFloat& other) {
        // Check for overflow
        if (boost::safe_float::check_addition_overflow(value_, other.value_)) {
            // Handle overflow
            return *this;
        }

        // Check for underflow
        if (boost::safe_float::check_addition_underflow(value_, other.value_)) {
            // Handle underflow
            return *this;
        }

        // Check for inexact results
        if (boost::safe_float::check_addition_inexact(value_, other.value_)) {
            // Handle inexact results
            return *this;
        }

        // Check for invalid results
        if (boost::safe_float::check_addition_invalid_result(value_, other.value_)) {
            // Handle invalid results
            return *this;
        }

        // Perform addition
        value_ += other.value_;
        return *this;
    }

    float value() const { return value_; }

private:
    float value_;
};
