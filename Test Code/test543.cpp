#include <SDL.h>

class CameraController {
private:
    double zoomLevel = 1.0;
    double panSpeed = 1.0;

public:
    void panUp() {
        // Implement the logic to move the camera upward based on the pan speed
    }

    void panDown() {
        // Implement the logic to move the camera downward based on the pan speed
    }

    void panLeft() {
        // Implement the logic to move the camera to the left based on the pan speed
    }

    void panRight() {
        // Implement the logic to move the camera to the right based on the pan speed
    }

    void zoomIn() {
        zoomLevel *= 1.1; // Increase the zoom level by a factor of 1.1
    }

    void zoomOut() {
        zoomLevel *= 0.9; // Decrease the zoom level by a factor of 0.9
    }

    bool keyPressed(const SDL_KeyboardEvent &arg) {
        if (arg.keysym.scancode == SDL_SCANCODE_UP) {
            panUp();
            return true;
        } else if (arg.keysym.scancode == SDL_SCANCODE_DOWN) {
            panDown();
            return true;
        } else if (arg.keysym.scancode == SDL_SCANCODE_LEFT) {
            panLeft();
            return true;
        } else if (arg.keysym.scancode == SDL_SCANCODE_RIGHT) {
            panRight();
            return true;
        } else if (arg.keysym.scancode == SDL_SCANCODE_LSHIFT) {
            zoomIn();
            return true;
        } else if (arg.keysym.scancode == SDL_SCANCODE_LCTRL) {
            zoomOut();
            return true;
        }
        return false;
    }
};
