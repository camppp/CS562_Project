#include <iostream>
#include <vector>

class GridWithMissingValues {
private:
  std::vector<std::vector<int>> grid_;
  int missing_val_;

public:
  // Constructor
  GridWithMissingValues(const std::vector<std::vector<int>>& grid, int missing_val)
      : grid_(grid), missing_val_(missing_val) {}

  // Check if a value equals the missing value
  bool EqualsMissingValue(int value) const {
    return value == missing_val_;
  }

  // Check if grid value is missing at a specific position
  bool GetMissingAt(size_t i, size_t j) const {
    return grid_[i][j] == missing_val_;
  }

  // Set a value as missing at a specific position
  void SetMissingAt(size_t i, size_t j) {
    grid_[i][j] = missing_val_;
  }
};
