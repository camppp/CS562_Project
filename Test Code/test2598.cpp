void handle_controller_event(const controller_event& e, game_controller& my_controller) {
    switch (e.my_event_type) {
        case event_type::controller_button_press:
        case event_type::controller_button_release: {
            my_controller.my_buttons_status[to_index(e.my_button)] = e.my_action;
            break;
        }
        case event_type::controller_axis_move: {
            my_controller.my_axis_positions[to_index(e.my_axis)] = e.my_axis_position;
            break;
        }
        default:
            // Handle other event types if needed
            break;
    }
}
