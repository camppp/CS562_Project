void handle_controller_event(const controller_event& event) {
    switch (event.my_action) {
        case controller_button_press:
            my_controller.my_buttons_status[event.my_button] = true;
            break;
        case controller_button_release:
            my_controller.my_buttons_status[event.my_button] = false;
            break;
        case controller_axis_move:
            my_controller.my_axis_positions[event.my_button] = event.my_action;
            break;
        default:
            break;
    }
}
