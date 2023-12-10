#include <vector>

void applyFilter(const std::vector<std::vector<int>>& inputImage, 
                 const std::vector<std::vector<int>>& filter, 
                 int filterSize, 
                 std::vector<std::vector<int>>& outputImage) {
    int height = inputImage.size();
    int width = inputImage[0].size();
    int filter_pivot = filterSize / 2;

    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            int sum = 0;
            for (int filter_y = 0; filter_y < filterSize; ++filter_y) {
                int filter_y_idx = row - filter_pivot + filter_y;
                if (filter_y_idx < 0 || filter_y_idx >= height)
                    continue;
                for (int filter_x = 0; filter_x < filterSize; ++filter_x) {
                    int filter_x_idx = col - filter_pivot + filter_x;
                    if (filter_x_idx < 0 || filter_x_idx >= width)
                        continue;
                    sum += inputImage[filter_y_idx][filter_x_idx] * filter[filter_y][filter_x];
                }
            }
            outputImage[row][col] = sum;
        }
    }
}
