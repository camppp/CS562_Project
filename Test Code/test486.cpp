#include <vector>
#include <algorithm>
#include <limits>

template <typename T>
std::vector<T> longestIncreasingSubsequence(const std::vector<T>& a) {
  T inf = std::numeric_limits<T>::max();
  std::vector<T> lis(a.size(), inf);
  for (const T& x: a) *std::lower_bound(lis.begin(), lis.end(), x) = x;
  auto i = std::lower_bound(lis.begin(), lis.end(), inf);
  return std::vector<T>(lis.begin(), i);
}

// Example usage
int main() {
  std::vector<int> input = {3, 4, -1, 0, 6, 2, 3};
  std::vector<int> result = longestIncreasingSubsequence(input);
  // Output the result
  for (const auto& num : result) {
    std::cout << num << " ";
  }
  return 0;
}
