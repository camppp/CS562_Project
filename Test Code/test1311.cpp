#include <opencv2/opencv.hpp>
#include "cvui.h"

#define WINDOW_NAME	"CVUI Canny Edge"

int main(int argc, const char *argv[])
{
    cv::Mat lena = cv::imread("lena.jpg");
    cv::Mat frame = lena.clone();
    int low_threshold = 50, high_threshold = 150;
    bool use_canny = false;

    cv::namedWindow(WINDOW_NAME);
    cvui::init(WINDOW_NAME);

    while (true) {
        frame = lena.clone();  // Reset frame to original image

        // Create GUI elements
        cvui::checkbox(frame, 10, 10, "Use Canny", &use_canny);
        cvui::trackbar(frame, 10, 40, 150, &low_threshold, 0, 255);
        cvui::trackbar(frame, 10, 70, 150, &high_threshold, 0, 255);

        // Apply Canny edge detection if enabled
        if (use_canny) {
            cv::Mat gray;
            cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);
            cv::Canny(gray, frame, low_threshold, high_threshold);
        }

        cvui::update();

        cv::imshow(WINDOW_NAME, frame);

        if (cv::waitKey(30) == 27) {
            break;
        }
    }

    return 0;
}
