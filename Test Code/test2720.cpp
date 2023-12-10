#include <iostream>

struct GUIElement {
    double x, y, w, h;
};

const double GUIELEMENT_COMPARE_DISTANCE_Y_THRESHOLD = 0.1; // Example threshold value

bool Compare(GUIElement* a, GUIElement* b) {
    double a_x = a->x + 0.5 * a->w;
    double a_y = a->y + 0.5 * a->h;
    double b_x = b->x + 0.5 * b->w;
    double b_y = b->y + 0.5 * b->h;
    if (a_y < b_y - GUIELEMENT_COMPARE_DISTANCE_Y_THRESHOLD) return true;
    if (a_y > b_y + GUIELEMENT_COMPARE_DISTANCE_Y_THRESHOLD) return false;
    return a->x < b->x;
}

int main() {
    GUIElement elem1 = {1.0, 2.0, 3.0, 4.0};
    GUIElement elem2 = {2.0, 3.0, 4.0, 5.0};
    std::cout << "Comparison result: " << Compare(&elem1, &elem2) << std::endl;
    return 0;
}
