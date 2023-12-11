#include <wayland-client.h>
#include <wayland-client-protocol.h>

class WaylandWindow {
public:
    WaylandWindow(int width, int height) {
        // Create a Wayland surface
        surface = wl_compositor_create_surface(compositor);

        // Create a Wayland window
        window = wl_window_create(surface, width, height);

        // Set the window title
        wl_window_set_title(window, "Wayland Window");
    }

    ~WaylandWindow() {
        // Destroy the Wayland window
        wl_window_destroy(window);

        // Destroy the Wayland surface
        wl_surface_destroy(surface);
    }

    void show() {
        // Show the Wayland window
        wl_window_show(window);
    }

    void hide() {
        // Hide the Wayland window
        wl_window_hide(window);
    }

    void resize(int width, int height) {
        // Resize the Wayland window
        wl_window_resize(window, width, height);
    }

    void destroy() {
        // Destroy the Wayland window
        wl_window_destroy(window);
    }

private:
    wl_compositor* compositor;
    wl_surface* surface;
    wl_window* window;
};
