void handleMouseInput(int state, Input* input) {
    switch (state) {
        case MOUSE_BUTTON_DOWN:
            input->setScrollUpMouseWheel(true);
            break;
        case MOUSE_BUTTON_UP:
            input->setScrollDownMouseWheel(true);
            break;
        case MOUSE_SCROLL:
            input->setScrollUpMouseWheel(true);
            input->setScrollDownMouseWheel(true);
            break;
        default:
            // Handle invalid state
            break;
    }
}
