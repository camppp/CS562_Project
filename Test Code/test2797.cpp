#include <opencv2/opencv.hpp>

using namespace cv;

void performImageProcessing(const Mat& I1, const Mat& I2, const Mat& mu1, const Mat& mu2, Mat& I1_I2, Mat& mu1_mu2) {
    // Calculate the element-wise multiplication of I1 and I2
    I1_I2 = I1.mul(I2);

    // Calculate the element-wise multiplication of mu1 and mu2
    mu1_mu2 = mu1.mul(mu2);
}
