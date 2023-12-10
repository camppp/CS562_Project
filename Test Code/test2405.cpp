#include <iostream>

// Assume the following definition for MousePixelPos and MotionDetector
struct MousePixelPos {
    int x, y;
};

class MotionDetector {
public:
    void OnMouseAction(const MousePixelPos& pos) {
        // Implementation of motion detection based on the mouse position
        std::cout << "Motion detected at position (" << pos.x << ", " << pos.y << ")" << std::endl;
    }
};

class CDetectorMouseController {
private:
    MotionDetector detector;

public:
    void OnMouseDClick();
};

void CDetectorMouseController::OnMouseDClick() {
    const MousePixelPos pos = MousePixelPos();  // Simulated mouse position
    detector.OnMouseAction(pos);
}

int main() {
    CDetectorMouseController controller;
    controller.OnMouseDClick();  // Simulate a double-click event
    return 0;
}
