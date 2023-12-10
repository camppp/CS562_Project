#include <opencv2/core.hpp>

std::pair<cv::Mat, cv::Mat> performImageProcessing(const ImageSet& a, const ImageSet& b) {
    // Calculate element-wise multiplication of imageSquare from set a with imageSquare from set b
    cv::Mat I1_I2 = a.imageSquare.mul(b.imageSquare);

    // Calculate element-wise multiplication of imageBlur from set a with imageBlur from set b
    cv::Mat mu1_mu2 = a.imageBlur.mul(b.imageBlur);

    return std::make_pair(I1_I2, mu1_mu2);
}
