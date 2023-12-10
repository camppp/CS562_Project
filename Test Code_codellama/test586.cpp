#include <opencv2/opencv.hpp>
#include "armor_detect.h"

using namespace cv;

int main()
{
    // Read video file
    VideoCapture cap("der.avi");
    if (!cap.isOpened())
    {
        std::cout << "Error opening video file" << std::endl;
        return -1;
    }

    // Create window for displaying video stream
    namedWindow("识别窗口", WINDOW_AUTOSIZE);

    // Initialize variables for contrast and brightness adjustments
    int g_nContrastValue = 0;
    int g_nBrightValue = 0;

    // Continuously process each frame of the video
    while (true)
    {
        // Read next frame from the video
        Mat frame;
        cap >> frame;

        // Apply contrast and brightness adjustments to the frame
        adjustContrast(frame, g_nContrastValue);
        adjustBrightness(frame, g_nBrightValue);

        // Detect and track the object of interest using the armor_detect.h header file and associated functions
        Mat objectMask = detectObject(frame);
        Mat trackedObject = trackObject(objectMask);

        // Display the tracked object in the "识别窗口" window
        imshow("识别窗口", trackedObject);

        // Check for user input to adjust contrast and brightness
        char key = waitKey(1);
        if (key == 'c')
        {
            g_nContrastValue += 10;
        }
        else if (key == 'b')
        {
            g_nBrightValue += 10;
        }
    }

    return 0;
}
