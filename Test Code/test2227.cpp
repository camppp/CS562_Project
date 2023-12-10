#include <opencv2/opencv.hpp>

std::vector<int> blockMatching(const std::vector<cv::Mat>& leftImage, const std::vector<cv::Mat>& rightImage, int bm_SAD_window_size, int bm_12_max_diff, int bm_min_disparity, int bm_num_disparities, int bm_speckle_window_size) {
    std::vector<int> disparityMap;

    // Perform block matching using the given parameters
    cv::Ptr<cv::StereoBM> bm = cv::StereoBM::create(bm_num_disparities, bm_SAD_window_size);
    bm->setPreFilterType(CV_STEREO_BM_XSOBEL);
    bm->setPreFilterSize(9);
    bm->setPreFilterCap(31);
    bm->setMinDisparity(bm_min_disparity);
    bm->setTextureThreshold(10);
    bm->setUniquenessRatio(15);
    bm->setSpeckleWindowSize(bm_speckle_window_size);
    bm->setSpeckleRange(32);
    bm->setDisp12MaxDiff(bm_12_max_diff);

    cv::Mat disparity;
    bm->compute(leftImage[0], rightImage[0], disparity);

    // Convert disparity map to vector of integers
    for (int i = 0; i < disparity.rows; i++) {
        for (int j = 0; j < disparity.cols; j++) {
            disparityMap.push_back(static_cast<int>(disparity.at<short>(i, j)));
        }
    }

    return disparityMap;
}
