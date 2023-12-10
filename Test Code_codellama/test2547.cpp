void applyFilter(const std::vector<std::vector<int>>& inputImage, 
                 const std::vector<std::vector<int>>& filter, 
                 int filterSize, 
                 std::vector<std::vector<int>>& outputImage) {
    // Check if the filter is a square
    if (filter.size() != filterSize || filter[0].size() != filterSize) {
        throw std::invalid_argument("Filter must be a square");
    }

    // Check if the input image and output image have the same dimensions
    if (inputImage.size() != outputImage.size() || inputImage[0].size() != outputImage[0].size()) {
        throw std::invalid_argument("Input image and output image must have the same dimensions");
    }

    // Iterate over the input image and apply the filter
    for (int i = 0; i < inputImage.size(); i++) {
        for (int j = 0; j < inputImage[0].size(); j++) {
            // Calculate the sum of the values in the filter that are within the boundaries of the input image
            int sum = 0;
            for (int k = 0; k < filterSize; k++) {
                for (int l = 0; l < filterSize; l++) {
                    if (i + k < inputImage.size() && j + l < inputImage[0].size()) {
                        sum += filter[k][l] * inputImage[i + k][j + l];
                    }
                }
            }

            // Store the result in the output image
            outputImage[i][j] = sum;
        }
    }
}
