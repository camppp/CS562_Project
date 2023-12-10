#include <opencv2/opencv.hpp>

std::pair<double, double> processImage(const cv::Mat& image, int num_lines, int avg_block_size) {
    // Initialize variables
    double sum_x_weighted = 0.0;
    double sum_y_weighted = 0.0;
    int num_blocks = 0;

    // Iterate through the rows of the image
    for (int i = 0; i < image.rows; i++) {
        // Check if the current row number satisfies the condition
        if (i % num_lines == 0) {
            // Calculate the average block size
            int block_size = avg_block_size * num_lines;

            // Calculate the sum of the x-weighted and y-weighted values
            sum_x_weighted += image.at<cv::Vec3b>(i, 0)[0] * block_size;
            sum_y_weighted += image.at<cv::Vec3b>(i, 0)[1] * block_size;

            // Increment the number of blocks
            num_blocks++;
        }
    }

    // Calculate the average x-weighted and y-weighted values
    double avg_x_weighted = sum_x_weighted / num_blocks;
    double avg_y_weighted = sum_y_weighted / num_blocks;

    // Return the result
    return std::make_pair(avg_x_weighted, avg_y_weighted);
}
