bool InputManager::IsMouseButtonClicked(uint button) const {
    // Check if the specified mouse button is currently in a clicked state
    if (button < 5) {
        return mouse_buttons_[button] == GLFW_PRESS;
    } else {
        return false;
    }
}
