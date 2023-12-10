#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "armor_detect.h"

using namespace cv;
using namespace std;

int main()
{
    Mat video1, new_image;
    int g_nContrastValue = 100;  // Initial contrast value
    int g_nBrightValue = -100;   // Initial brightness value
    VideoCapture video("der.avi");  // Open the video file "der.avi"
    namedWindow("识别窗口", CV_WINDOW_AUTOSIZE);  // Create a window for displaying the video stream

    while (1) {
        // Read the next frame from the video
        video >> video1;

        // Check for end of video
        if (video1.empty()) {
            break;
        }

        // Apply contrast and brightness adjustments to the frame
        video1.convertTo(new_image, -1, g_nContrastValue / 100.0, g_nBrightValue);

        // Perform object detection and tracking using the armor_detect.h functions
        // Add your code here to call the appropriate functions for object detection and tracking

        // Display the processed frame in the window
        imshow("识别窗口", new_image);

        // Wait for a short duration and check for user input to exit the loop
        if (waitKey(30) >= 0) {
            break;
        }
    }

    // Release the video capture and destroy the window
    video.release();
    destroyWindow("识别窗口");
    return 0;
}
