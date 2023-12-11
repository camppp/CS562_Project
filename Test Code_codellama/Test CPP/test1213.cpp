float calculateZoomX(float zoom_y, double fx, int image_width_) {
    // Calculate the zoom factor along the x-axis based on the zoom factor along the y-axis
    float zoom_x = zoom_y * (image_width_ / fx);
    return zoom_x;
}
