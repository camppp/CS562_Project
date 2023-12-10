#include <iostream>
#include <cmath>

class CameraController {
public:
    CameraController() : zoomLevel(1.0), panSpeed(1.0) {}

    void keyPressed(int key) {
        switch (key) {
            case 'w':
                panUp();
                break;
            case 's':
                panDown();
                break;
            case 'a':
                panLeft();
                break;
            case 'd':
                panRight();
                break;
            case '+':
                zoomIn();
                break;
            case '-':
                zoomOut();
                break;
        }
    }

    void panUp() {
        position.y += panSpeed;
    }

    void panDown() {
        position.y -= panSpeed;
    }

    void panLeft() {
        position.x -= panSpeed;
    }

    void panRight() {
        position.x += panSpeed;
    }

    void zoomIn() {
        zoomLevel *= 1.1;
    }

    void zoomOut() {
        zoomLevel *= 0.9;
    }

private:
    double zoomLevel;
    double panSpeed;
    glm::vec2 position;
};
