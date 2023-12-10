#include "../include/cpp_lane_line_detection.h"

int main(int argc, char * argv[])
{
    // Iterate through the input images
    for (int i = 0; i < argc; i++) {
        // Read the input image from file
        cv::Mat inputImage = cv::imread(argv[i]);

        // Preprocess the image
        cv::Mat processedImage;
        // Apply grayscale conversion
        cv::cvtColor(inputImage, processedImage, CV_BGR2GRAY);
        // Apply Gaussian blurring
        cv::GaussianBlur(processedImage, processedImage, cv::Size(5, 5), 0);
        // Apply edge detection
        cv::Canny(processedImage, processedImage, 50, 150, 3);

        // Apply region of interest mask
        cv::Mat maskedImage;
        // Define the region of interest
        cv::Rect roi(0, 0, inputImage.cols, inputImage.rows);
        // Apply the region of interest mask
        cv::bitwise_and(processedImage, processedImage, maskedImage, roi);

        // Detect lines using Hough transform
        std::vector<cv::Vec4i> lines;
        // Define the Hough transform parameters
        double rho = 1;
        double theta = CV_PI / 180;
        double threshold = 150;
        double minLineLength = 10;
        double maxLineGap = 10;
        // Apply the Hough transform
        cv::HoughLinesP(maskedImage, lines, rho, theta, threshold, minLineLength, maxLineGap);

        // Draw the detected lines on the original image
        cv::Mat outputImage = inputImage.clone();
        for (size_t i = 0; i < lines.size(); i++) {
            cv::Vec4i line = lines[i];
            cv::line(outputImage, cv::Point(line[0], line[1]), cv::Point(line[2], line[3]), cv::Scalar(0, 255, 0), 3);
        }

        // Display the output image
        cv::imshow("Lane Line Detection", outputImage);
        cv::waitKey(0);
    }

    return 0;
}
