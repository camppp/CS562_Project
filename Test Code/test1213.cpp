#include <iostream>

double calculateZoomX(float zoom_y, double fx, int image_width_) {
    // Calculate the zoom factor along the x-axis based on the zoom factor along the y-axis
    double zoom_x = (2.0 * fx / static_cast<double>(image_width_)) / zoom_y;
    return zoom_x;
}

int main() {
    float zoom_y = 1.5;  // Example zoom factor along the y-axis
    double fx = 100.0;    // Example focal length in the x-direction
    int image_width_ = 800;  // Example image width

    double zoom_x = calculateZoomX(zoom_y, fx, image_width_);
    std::cout << "Calculated zoom factor along the x-axis: " << zoom_x << std::endl;

    return 0;
}
