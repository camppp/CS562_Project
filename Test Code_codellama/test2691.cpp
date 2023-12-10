#include <iostream>

class NFmiDataModifierGreaterThan {
public:
  NFmiDataModifierGreaterThan(double threshold) : threshold_(threshold) {}

  void operator()(double& value) const {
    if (value > threshold_) {
      value = threshold_;
    }
  }

private:
  double threshold_;
};

int main() {
  NFmiDataModifierGreaterThan modifier(10.0);
  double value = 20.0;
  modifier(value);
  std::cout << "Value after modification: " << value << std::endl;
  return 0;
}
