#include <iostream>
#include <cmath>
#include <stdexcept>

class ZeroInputException : public std::exception {
public:
  const char* what() const noexcept override {
    return "Zero input is not allowed";
  }
};

int M(int input) {
  if (input == 0) {
    throw ZeroInputException();
  } else if (input < 0) {
    throw std::out_of_range("Negative input is out of range");
  } else {
    double squareRoot = std::sqrt(input);
    int roundedValue = static_cast<int>(std::round(squareRoot));
    return roundedValue;
  }
}

int main() {
  try {
    int result = M(0);
    std::cout << "Result: " << result << std::endl;
  } catch (const ZeroInputException& e) {
    std::cout << "Exception: " << e.what() << std::endl;
    return 1;
  } catch (const std::out_of_range& e) {
    std::cout << "Exception: " << e.what() << std::endl;
    return 1;
  } catch (...) {
    std::cout << "ooops" << std::endl;
    return 1;
  }
  return 0;
}
