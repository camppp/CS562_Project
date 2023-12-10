#include <iostream>

bool isPrime(int n) {
  if (n <= 1) {
    return false;
  }
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  // Test cases
  std::cout << isPrime(7) << std::endl;  // Output: 1 (true)
  std::cout << isPrime(4) << std::endl;  // Output: 0 (false)
  return 0;
}
