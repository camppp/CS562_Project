#include <cassert>
#include <string>

class window_extractor {
 public:
  // Constructor
  window_extractor(int top_left_x, int top_left_y, int bottom_right_x, int bottom_right_y, int center_x, int center_y, PaddingType padding_type) {
    // Initialize the window extractor with the given parameters
    Initialize(top_left_x, top_left_y, bottom_right_x, bottom_right_y, center_x, center_y, padding_type);
  }

  // Initialize the window extractor with the given parameters
  absl::Status Initialize(int top_left_x, int top_left_y, int bottom_right_x, int bottom_right_y, int center_x, int center_y, PaddingType padding_type) {
    // Validate the input parameters
    if (top_left_x < 0 || top_left_y < 0 || bottom_right_x < 0 || bottom_right_y < 0 || center_x < 0 || center_y < 0) {
      return absl::Status(absl::StatusCode::kInvalidArgument, "Invalid input parameters");
    }

    if (bottom_right_x - top_left_x <= 0 || bottom_right_y - top_left_y <= 0) {
      return absl::Status(absl::StatusCode::kInvalidArgument, "Invalid window size");
    }

    if (padding_type != PaddingType::kNone && padding_type != PaddingType::kZero && padding_type != PaddingType::kSymmetric) {
      return absl::Status(absl::StatusCode::kInvalidArgument, "Invalid padding type");
    }

    // Initialize the window extractor with the given parameters
    top_left_ = {top_left_x, top_left_y};
    bottom_right_ = {bottom_right_x, bottom_right_y};
    center_ = {center_x, center_y};
    padding_type_ = padding_type;

    return absl::Status();
  }

  // Extract a window of the specified size from the 2D grid
  absl::Status ExtractWindow(const std::vector<std::vector<int>>& grid, int window_width, int window_height, std::vector<std::vector<int>>& window) {
    // Validate the input parameters
    if (window_width <= 0 || window_height <= 0) {
      return absl::Status(absl::StatusCode::kInvalidArgument, "Invalid window size");
    }

    if (grid.size() < top_left_.x || grid[0].size() < top_left_.y) {
      return absl::Status(absl::StatusCode::kInvalidArgument, "Invalid top-left corner position");
    }

    if (grid.size() < bottom_right_.x || grid[0].size() < bottom_right_.y) {
      return absl::Status(absl::StatusCode::kInvalidArgument, "Invalid bottom-right corner position");
    }

    // Extract the window from the 2D grid
    for (int i = top_left_.x; i < bottom_right_.x; i++) {
      for (int j = top_left_.y; j < bottom_right_.y; j++) {
        window[i - top_left_.x][j - top_left_.y] = grid[i][j];
      }
    }

    return absl::Status();
  }

 private:
  // Top-left corner position
  std::pair<int, int> top_left_;

  // Bottom-right corner position
  std::pair<int, int> bottom_right_;

  // Center position
  std::pair<int, int> center_;

  // Padding type
  PaddingType padding_type_;
};
