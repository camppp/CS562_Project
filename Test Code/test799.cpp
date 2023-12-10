#include <gtest/gtest.h>
#include <stan/math.hpp>

// Define the custom mathematical function for subtraction
struct op_subtraction_f {
  template <typename T1, typename T2>
  static auto apply(const T1& x1, const T2& x2) {
    return x1 - x2;
  }
};

// Define the unit test for subtraction operator
TEST(mathMixCore, opratorSubraction) {
  // Test common arguments for subtraction operation
  stan::math::test::test_common_args<op_subtraction_f, false>();
}

// Add more test cases to cover various scenarios and edge cases for subtraction operation
TEST(mathMixCore, opratorSubractionEdgeCases) {
  // Test subtraction with zero
  EXPECT_EQ(op_subtraction_f::apply(5, 0), 5);

  // Test subtraction with negative numbers
  EXPECT_EQ(op_subtraction_f::apply(10, -3), 13);

  // Test subtraction with floating point numbers
  EXPECT_DOUBLE_EQ(op_subtraction_f::apply(3.5, 1.2), 2.3);
}
