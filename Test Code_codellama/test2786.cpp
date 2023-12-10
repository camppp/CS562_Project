#include <opencv2/opencv.hpp>

cv::Mat normalizeImage(cv::Mat image1, cv::Mat image2) {
    // Compute the element-wise multiplication of image1 and image2
    cv::Mat output = image1.mul(image2);

    // Find the minimum and maximum pixel values of output
    double minVal, maxVal;
    cv::minMaxLoc(output, &minVal, &maxVal);

    // Normalize the pixel values in output to the range [0, 1]
    output.convertTo(output, CV_8UC1, 255.0 / (maxVal - minVal), -minVal * 255.0 / (maxVal - minVal));

    return output;
}
