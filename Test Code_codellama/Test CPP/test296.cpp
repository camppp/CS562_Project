#include <iostream>
#include <gpcl.hpp>

int main() {
  // Create a container to store the integers
  gpcl::vector<int> integers;

  // Read the integers from the standard input
  while (true) {
    int input;
    std::cin >> input;
    if (std::cin.eof()) {
      break;
    }
    integers.push_back(input);
  }

  // Calculate the sum of all the integers
  int sum = 0;
  for (int i : integers) {
    sum += i;
  }

  // Print the result to the standard output
  std::cout << "The sum of the integers is: " << sum << std::endl;

  return 0;
}
