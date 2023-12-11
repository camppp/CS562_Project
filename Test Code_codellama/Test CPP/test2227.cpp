std::vector<int> blockMatching(const std::vector<cv::Mat>& leftImage, const std::vector<cv::Mat>& rightImage, int bm_SAD_window_size, int bm_12_max_diff, int bm_min_disparity, int bm_num_disparities, int bm_speckle_window_size) {
    // Initialize the disparity map with the minimum disparity value
    std::vector<int> disparityMap(leftImage.size(), bm_min_disparity);

    // Iterate over the rows of the left image
    for (int y = 0; y < leftImage.rows; y++) {
        // Iterate over the columns of the left image
        for (int x = 0; x < leftImage.cols; x++) {
            // Compute the SAD between the current pixel and the corresponding pixel in the right image
            int sad = 0;
            for (int dy = -bm_SAD_window_size; dy <= bm_SAD_window_size; dy++) {
                for (int dx = -bm_SAD_window_size; dx <= bm_SAD_window_size; dx++) {
                    int leftPixel = leftImage.at<uchar>(y + dy, x + dx);
                    int rightPixel = rightImage.at<uchar>(y + dy, x + dx);
                    sad += abs(leftPixel - rightPixel);
                }
            }

            // If the SAD is less than the maximum allowed difference, update the disparity map
            if (sad <= bm_12_max_diff) {
                disparityMap[y * leftImage.cols + x] = (sad << 12) / (bm_SAD_window_size * bm_SAD_window_size);
            }
        }
    }

    // Filter out speckle noise in the disparity map using a median filter
    for (int y = 0; y < leftImage.rows; y++) {
        for (int x = 0; x < leftImage.cols; x++) {
            int median = disparityMap[y * leftImage.cols + x];
            for (int dy = -bm_speckle_window_size; dy <= bm_speckle_window_size; dy++) {
                for (int dx = -bm_speckle_window_size; dx <= bm_speckle_window_size; dx++) {
                    int neighbor = disparityMap[y + dy * leftImage.rows + x + dx * leftImage.cols];
                    if (neighbor < median) {
                        median = neighbor;
                    }
                }
            }
            disparityMap[y * leftImage.cols + x] = median;
        }
    }

    return disparityMap;
}
