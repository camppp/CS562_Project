#include <cmath>
#include <stdexcept>

int M(int input) {
  try {
    if (input == 0) {
      throw ZeroInputException();
    } else if (input < 0) {
      throw std::out_of_range("Input must be non-negative");
    }

    double sqrt = std::sqrt(input);
    int rounded = std::round(sqrt);
    return rounded;
  } catch (const ZeroInputException& e) {
    printf("ZeroInputException: %s\n", e.what());
    return 1;
  } catch (const std::out_of_range& e) {
    printf("std::out_of_range: %s\n", e.what());
    return 2;
  } catch (...) {
    printf("Unknown exception\n");
    return 3;
  }
}
