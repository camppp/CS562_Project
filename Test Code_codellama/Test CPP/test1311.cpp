#include <opencv2/opencv.hpp>
#include <cvui.h>

int main() {
  // Load the Lena image
  cv::Mat lena = cv::imread("lena.jpg");

  // Create a clone of the Lena image
  cv::Mat frame = lena.clone();

  // Initialize the low and high threshold values
  int low_threshold = 50;
  int high_threshold = 150;

  // Initialize the use_canny flag
  bool use_canny = false;

  // Create a window for the GUI
  cvui::init("Image Processing");

  // Create a checkbox for the Canny edge detection
  cvui::checkbox("Use Canny Edge Detection", &use_canny);

  // Create a trackbar for the low threshold value
  cvui::trackbar("Low Threshold", &low_threshold, 0, 255);

  // Create a trackbar for the high threshold value
  cvui::trackbar("High Threshold", &high_threshold, 0, 255);

  // Create a button to apply the Canny edge detection
  cvui::button("Apply Canny Edge Detection");

  // Create a button to reset the image
  cvui::button("Reset Image");

  // Create a window for the output image
  cv::namedWindow("Output Image");

  // Create a loop to handle user input and update the output image
  while (cvui::waitKey(1) == 0) {
    // Update the output image based on the user's input
    if (use_canny) {
      cv::Canny(frame, frame, low_threshold, high_threshold);
    }

    // Display the output image
    cv::imshow("Output Image", frame);

    // Check for user input
    if (cvui::buttonPressed("Apply Canny Edge Detection")) {
      use_canny = true;
    }

    if (cvui::buttonPressed("Reset Image")) {
      frame = lena.clone();
      use_canny = false;
    }
  }

  // Release the resources
  cv::destroyAllWindows();

  return 0;
}
