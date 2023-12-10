#include <iostream>

class NFmiDataModifierGreaterThan {
public:
  NFmiDataModifierGreaterThan(double threshold) : m_threshold(threshold) {}

  void operator()(double& value) const {
    if (value > m_threshold) {
      value = m_threshold;
    }
  }

private:
  double m_threshold;
};

int main() {
  // Example usage
  NFmiDataModifierGreaterThan modifier(10.0);
  double value = 15.0;
  modifier(value);
  std::cout << "Modified value: " << value << std::endl;  // Output: Modified value: 10.0

  value = 5.0;
  modifier(value);
  std::cout << "Modified value: " << value << std::endl;  // Output: Modified value: 5.0

  return 0;
}
