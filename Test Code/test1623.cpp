#include <opencv2/opencv.hpp>

void imageProcessing(cv::Mat &imgFrame2Copy) {
    // Convert the input image to grayscale
    cv::Mat grayImage;
    cv::cvtColor(imgFrame2Copy, grayImage, cv::COLOR_BGR2GRAY);

    // Apply Gaussian blur with a kernel size of 5x5
    cv::GaussianBlur(grayImage, grayImage, cv::Size(5, 5), 0);

    // Perform Canny edge detection with threshold values of 100 and 200
    cv::Canny(grayImage, imgFrame2Copy, 100, 200);
}
