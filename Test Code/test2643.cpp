#include <iostream>

namespace test1 {
  template <class... T> void foo() {
    int values[sizeof...(T)+1] = { T::value... };
    for (int i = 0; i < sizeof...(T)+1; ++i) {
      std::cout << values[i] << " ";
    }
    std::cout << std::endl;
  }

  void test() {
    // Example usage
    foo<int, double, char>(1, 2.5, 'a');
  }
}
