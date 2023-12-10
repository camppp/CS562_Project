#include <iostream>

struct Camera {
    float near_plane;
    float far_plane;
    float fov_y;
    float aspect_ratio;
    float viewport_width;
    float viewport_height;
    float zoom;
    bool is_perspective;

    void init_perspective(float near_plane, float far_plane, float fov_y, float aspect_ratio) {
        this->near_plane = near_plane;
        this->far_plane = far_plane;
        this->fov_y = fov_y;
        this->aspect_ratio = aspect_ratio;
        is_perspective = true;
    }

    void init_orthographic(float near_plane, float far_plane, float viewport_width, float viewport_height, float zoom) {
        this->near_plane = near_plane;
        this->far_plane = far_plane;
        this->viewport_width = viewport_width;
        this->viewport_height = viewport_height;
        this->zoom = zoom;
        is_perspective = false;
    }

    void reset() {
        near_plane = 0.1f;
        far_plane = 1000.0f;
        fov_y = 45.0f;
        aspect_ratio = 16.0f / 9.0f;
        viewport_width = 1280.0f;
        viewport_height = 720.0f;
        zoom = 1.0f;
        is_perspective = true;
    }

    void set_viewport_size(float width, float height) {
        viewport_width = width;
        viewport_height = height;
    }

    void set_zoom(float zoom) {
        this->zoom = zoom;
    }

    void set_aspect_ratio(float aspect_ratio) {
        this->aspect_ratio = aspect_ratio;
    }

    void switch_projection() {
        is_perspective = !is_perspective;
    }
};
