class RandomCropDecodeResizeOp {
 public:
  RandomCropDecodeResizeOp(int target_height, int target_width, float scale_lb)
      : target_height_(target_height), target_width_(target_width), scale_lb_(scale_lb) {}

  void random_crop(cv::Mat& image) {
    // Randomly crop the input image to the specified target height and width.
    int x = rand() % (image.cols - target_width_);
    int y = rand() % (image.rows - target_height_);
    cv::Rect crop_rect(x, y, target_width_, target_height_);
    cv::Mat cropped_image = image(crop_rect);
  }

  void decode(cv::Mat& image) {
    // Decode the cropped image.
    cv::Mat decoded_image;
    cv::imdecode(image, CV_LOAD_IMAGE_UNCHANGED, decoded_image);
  }

  void resize(cv::Mat& image) {
    // Resize the decoded image based on the scale lower bound.
    cv::Mat resized_image;
    cv::resize(decoded_image, resized_image, cv::Size(target_width_, target_height_), 0, 0, CV_INTER_LINEAR);
  }

 private:
  int target_height_;
  int target_width_;
  float scale_lb_;
};
