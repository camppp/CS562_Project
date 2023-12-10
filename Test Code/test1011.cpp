class drawable_rectangle {
public:
    // Constructor
    drawable_rectangle(int w, int h) : width(w), height(h), cleared(false) {}

    // Set dimensions
    void set_dimensions(int w, int h) {
        width = w;
        height = h;
    }

    // Draw rectangle
    void draw() {
        // Draw rectangle using current dimensions
    }

    // Clear rectangle
    void clear() {
        if (!cleared) {
            // Clear rectangle contents
            cleared = true;
        }
    }

private:
    int width;
    int height;
    bool cleared;
};
