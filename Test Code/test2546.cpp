#include <opencv2/opencv.hpp>
#include <opencv2/cudaimgproc.hpp>

void customThreshold(cv::cuda::GpuMat& channel, float lowerLimit, cv::cuda::Stream& stream) {
    cv::cuda::threshold(channel, channel, lowerLimit, 255, cv::THRESH_TOZERO_INV, stream);
    cv::cuda::threshold(channel, channel, lowerLimit, 255, cv::THRESH_BINARY, stream);
}

int main() {
    // Assuming channels, BlobLower, and stream are properly initialized

    // Perform custom thresholding on each channel using CUDA-accelerated function
    customThreshold(channels[0], BlobLower[0], stream);
    customThreshold(channels[1], BlobLower[1], stream);
    customThreshold(channels[2], BlobLower[2], stream);

    // Further processing or output of the thresholded image channels
    // ...

    return 0;
}
