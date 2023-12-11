class viewport {
private:
    // Reference to the window object
    window& m_wnd;

    // Dimensions of the viewport
    point_type m_viewport_dimensions;

    // Position of the viewport within the window
    point_type m_viewport_position;

    // Initialize the viewport
    void init() {
        // Set the dimensions and position of the viewport
        m_viewport_dimensions = m_wnd.get_dimensions();
        m_viewport_position = m_wnd.get_position();
    }

public:
    // Constructor
    viewport(window& wnd) : m_wnd(wnd) {
        init();
    }

    // Convert coordinates from viewport space to screen space
    pixel_type viewport_to_screen(const point_type& viewport_coord) {
        // Calculate the screen coordinates based on the dimensions and position of the viewport
        pixel_type screen_coord = m_viewport_position + (viewport_coord - m_viewport_dimensions / 2);
        return screen_coord;
    }
};
