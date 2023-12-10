#include <iostream>
#include <vector>

// Define the filter class
class hole_filling_filter {
public:
    // Constructor for initializing the filter with default mode
    hole_filling_filter() : mode(0) {}

    // Constructor for initializing the filter with specified mode
    hole_filling_filter(int mode) : mode(mode) {}

    // Method to set the hole filling mode
    void set_mode(int mode) {
        this->mode = mode;
    }

    // Method to fill the holes in the depth image based on the selected mode
    void fill_holes(std::vector<std::vector<float>>& depth_image) {
        for (int i = 0; i < depth_image.size(); ++i) {
            for (int j = 0; j < depth_image[i].size(); ++j) {
                if (depth_image[i][j] == 0) {
                    switch (mode) {
                        case 0:  // fill_from_left
                            if (j > 0) {
                                depth_image[i][j] = depth_image[i][j - 1];
                            }
                            break;
                        case 1:  // farest_from_around
                            // Implementation logic to find the furthest neighboring pixel value
                            break;
                        case 2:  // nearest_from_around
                            // Implementation logic to find the nearest neighboring pixel value
                            break;
                        default:
                            std::cerr << "Invalid mode selected" << std::endl;
                    }
                }
            }
        }
    }

private:
    int mode;  // Mode for hole filling
};

int main() {
    // Example usage of the hole_filling_filter
    std::vector<std::vector<float>> depth_image = {
        {1.2, 0, 1.5, 0, 1.8},
        {0, 2.3, 0, 2.6, 0},
        {3.1, 0, 3.4, 0, 3.7}
    };

    hole_filling_filter filter(1);  // Initialize filter with mode 1
    filter.fill_holes(depth_image);  // Fill holes in the depth image based on the selected mode

    // Output the filled depth image
    for (const auto& row : depth_image) {
        for (const auto& value : row) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
