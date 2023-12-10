#include <iostream>
#include <tuple>

// Define the Sum3 function
int Sum3(int x, int y, int z) {
  return x + y + z;
}

// Define the Prod3 function
int Prod3(int x, int y, int z) {
  return x * y * z;
}

// Define the ApplyTuple function
template <typename F, typename... Args>
auto ApplyTuple(F&& f, std::tuple<Args...>&& t) {
  return std::forward<F>(f)(std::get<0>(t), std::get<1>(t), std::get<2>(t));
}

int main() {
  // Create a tuple of arguments
  int x = 10;
  int y = 13;
  int z = 22;
  auto test_tup = std::make_tuple(x, y, z);

  // Apply the tuple to the Sum3 function
  std::cout << "Sum3(" << x << "," << y << "," << z << ") = "
            << ApplyTuple(Sum3, test_tup) << std::endl;

  // Apply the tuple to the Prod3 function
  std::cout << "Prod3(" << x << "," << y << "," << z << ") = "
            << ApplyTuple(Prod3, test_tup) << std::endl;

  return 0;
}
