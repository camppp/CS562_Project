#include <iostream>

class ResizableComponent {
private:
    int old_comp_size;

public:
    ResizableComponent() : old_comp_size(0) {}

    int get_size() {
        // Method to get the current size of the component
        // Implementation not shown
        return 0;  // Placeholder return value
    }

    void recalc_sliders(int new_size) {
        // Method to recalculate sliders based on the new size
        // Implementation not shown
    }

    void resize() {
        int new_size = get_size();
        if (new_size != old_comp_size) {
            recalc_sliders(new_size);
            old_comp_size = new_size;
        }
    }
};
