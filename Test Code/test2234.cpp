void center(float avail_width, float element_width, float padding = 0) {
    float position = avail_width / 2 - element_width / 2 + padding;
    // Add the padding to the position if it is provided
    if (padding > 0) {
        position += padding;
    }
    // Set the position of the element
    set_position(position);
}
