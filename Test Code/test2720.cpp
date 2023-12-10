bool Compare(GUIElement* a, GUIElement* b) {
    // Calculate the center coordinates of each GUI element
    float center_x_a = a->x + 0.5 * a->w;
    float center_y_a = a->y + 0.5 * a->h;
    float center_x_b = b->x + 0.5 * b->w;
    float center_y_b = b->y + 0.5 * b->h;

    // Check if the center_y values are within the threshold
    if (center_y_a - center_y_b > GUIELEMENT_COMPARE_DISTANCE_Y_THRESHOLD ||
        center_y_a - center_y_b < -GUIELEMENT_COMPARE_DISTANCE_Y_THRESHOLD) {
        return false;
    }

    // Compare the x coordinates of the GUI elements
    return a->x < b->x;
}
