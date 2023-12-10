#include <opencv2/opencv.hpp>

cv::Mat normalizeImage(cv::Mat image1, cv::Mat image2) {
    // Perform element-wise multiplication of image1 and image2
    cv::Mat output = image1.mul(image2);

    // Find the minimum and maximum pixel values in the output matrix
    double minVal, maxVal;
    cv::minMaxLoc(output, &minVal, &maxVal);

    // Normalize the pixel values in the output matrix to the range [0, 1]
    output = (output - minVal) / (maxVal - minVal);

    return output;
}
