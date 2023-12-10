#include <opencv2/opencv.hpp>
#include <opencv2/superres.hpp>

using namespace cv;
using namespace cv::superres;

Ptr<FrameSource> createFrameSource_Camera(int cameraId)
{
    // Create a new frame source for the camera
    Ptr<FrameSource> frameSource = createFrameSource_Video(cameraId);

    // Set the frame source to use the camera input
    frameSource->setInput(cameraId);

    // Set the frame source to use the super resolution module
    frameSource->setSuperResolution(true);

    // Return the frame source
    return frameSource;
}
