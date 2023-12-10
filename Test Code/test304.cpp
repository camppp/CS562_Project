float calculateScalingFactor(int screen_w, int screen_h) {
    float scale_y = (float)screen_h / 1080;
    if (scale_y > 1.0f) {
        scale_y = 1.0f;
    }
    return scale_y;
}
