#include "../include/cpp_lane_line_detection.h"

int main(int argc, char * argv[])
{
    // Iterate through the input images
    for (int i = 1; i < argc; i++) {
        // Read the input image from file
        cv::Mat inputImage = cv::imread(argv[i]);

        // Preprocess the image
        cv::Mat grayImage, blurredImage, edgeImage;
        cv::cvtColor(inputImage, grayImage, cv::COLOR_BGR2GRAY);
        cv::GaussianBlur(grayImage, blurredImage, cv::Size(5, 5), 0);
        cv::Canny(blurredImage, edgeImage, 50, 150);

        // Apply region of interest mask
        cv::Mat mask = cv::Mat::zeros(edgeImage.size(), edgeImage.type());
        cv::Point pts[4] = {cv::Point(100, edgeImage.rows), cv::Point(450, 300), cv::Point(550, 300), cv::Point(edgeImage.cols - 100, edgeImage.rows)};
        cv::fillConvexPoly(mask, pts, 4, cv::Scalar(255, 255, 255));
        cv::bitwise_and(edgeImage, mask, edgeImage);

        // Detect lines using Hough transform
        std::vector<cv::Vec4i> lines;
        cv::HoughLinesP(edgeImage, lines, 1, CV_PI / 180, 50, 50, 10);

        // Draw the detected lines on the original image
        for (size_t i = 0; i < lines.size(); i++) {
            cv::Vec4i line = lines[i];
            cv::line(inputImage, cv::Point(line[0], line[1]), cv::Point(line[2], line[3]), cv::Scalar(0, 0, 255), 3, cv::LINE_AA);
        }

        // Display the output image
        cv::imshow("Lane Line Detection", inputImage);
        cv::waitKey(0);
    }

    return 0;
}
