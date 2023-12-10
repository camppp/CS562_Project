// MouseButton.h

#include <iostream>

enum class MouseButton {
    Left,
    Middle,
    Right,
    WheelUp,
    WheelDown
};

std::ostream& operator<<(std::ostream& os, const MouseButton& button) {
    switch (button) {
        case MouseButton::Left:
            return os << "Left";
        case MouseButton::Middle:
            return os << "Middle";
        case MouseButton::Right:
            return os << "Right";
        case MouseButton::WheelUp:
            return os << "WheelUp";
        case MouseButton::WheelDown:
            return os << "WheelDown";
    }
}
