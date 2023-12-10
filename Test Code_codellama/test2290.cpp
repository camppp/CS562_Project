#include <iostream>
#include <cmath>
#include <igamma_small_data.ipp>
#include <igamma_big_data.ipp>

template <typename T>
void do_test_gamma_2(const std::vector<T>& data, const std::string& name, const std::string& description) {
  // Perform round trip sanity checks on the incomplete gamma values
  for (size_t i = 0; i < data.size(); i++) {
    T x = data[i];
    T a = 1.0;
    T y = igamma(a, x);
    T z = igamma(a, y);
    if (std::abs(x - z) > 1e-6) {
      std::cout << "Round trip sanity check failed for " << name << " with input " << x << " and output " << y << "." << std::endl;
      std::cout << "Expected output: " << x << std::endl;
      std::cout << "Actual output: " << z << std::endl;
      return;
    }
  }

  // Print a success message
  std::cout << "Round trip sanity checks passed for " << name << "." << std::endl;
}

int main() {
  // Perform round trip sanity checks on small incomplete gamma values
  do_test_gamma_2<double>(igamma_small_data, "small incomplete gamma values", "small");

  // Perform round trip sanity checks on large incomplete gamma values
  do_test_gamma_2<double>(igamma_big_data, "large incomplete gamma values", "large");

  return 0;
}
