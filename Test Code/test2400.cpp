#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n, k;
  std::cin >> n;
  std::vector<int> sequence(n);
  for (int i = 0; i < n; i++) {
    std::cin >> sequence[i];
  }
  std::cin >> k;

  std::nth_element(sequence.begin(), sequence.begin() + k - 1, sequence.end());
  std::cout << sequence[k - 1] << std::endl;

  return 0;
}
