class hole_filling_filter {
public:
    hole_filling_filter(int mode) {
        this->mode = mode;
    }

    void filter(const cv::Mat& depth_image) {
        cv::Mat filtered_image;
        if (mode == 0) {
            // Use the value from the left neighbor pixel to fill the hole
            filtered_image = depth_image.clone();
            for (int i = 0; i < depth_image.rows; i++) {
                for (int j = 0; j < depth_image.cols; j++) {
                    if (depth_image.at<float>(i, j) == 0) {
                        filtered_image.at<float>(i, j) = depth_image.at<float>(i, j - 1);
                    }
                }
            }
        } else if (mode == 1) {
            // Use the value from the neighboring pixel which is furthest away from the sensor
            filtered_image = depth_image.clone();
            for (int i = 0; i < depth_image.rows; i++) {
                for (int j = 0; j < depth_image.cols; j++) {
                    if (depth_image.at<float>(i, j) == 0) {
                        float max_distance = 0;
                        for (int k = -1; k <= 1; k++) {
                            for (int l = -1; l <= 1; l++) {
                                if (depth_image.at<float>(i + k, j + l) > max_distance) {
                                    max_distance = depth_image.at<float>(i + k, j + l);
                                }
                            }
                        }
                        filtered_image.at<float>(i, j) = max_distance;
                    }
                }
            }
        } else if (mode == 2) {
            // Use the value from the neighboring pixel closest to the sensor
            filtered_image = depth_image.clone();
            for (int i = 0; i < depth_image.rows; i++) {
                for (int j = 0; j < depth_image.cols; j++) {
                    if (depth_image.at<float>(i, j) == 0) {
                        float min_distance = 1000000;
                        for (int k = -1; k <= 1; k++) {
                            for (int l = -1; l <= 1; l++) {
                                if (depth_image.at<float>(i + k, j + l) < min_distance) {
                                    min_distance = depth_image.at<float>(i + k, j + l);
                                }
                            }
                        }
                        filtered_image.at<float>(i, j) = min_distance;
                    }
                }
            }
        }
        // Display the filtered image
        cv::imshow("Filtered Image", filtered_image);
        cv::waitKey(0);
    }

private:
    int mode;
};
