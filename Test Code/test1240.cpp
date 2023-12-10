Ptr<FrameSource> cv::superres::createFrameSource_Camera(int deviceId)
{
    VideoCapture capture(deviceId);
    if (!capture.isOpened()) {
        CV_Error(cv::Error::StsError, "Failed to open camera with the specified device ID");
        return Ptr<FrameSource>();
    }

    return makePtr<CameraFrameSource>(capture);
}
