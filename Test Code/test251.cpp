void handleMessage(int messageType, int data) {
    switch (messageType) {
        case 0: // Button message
            buttons = data;
            new_buttons_msg = true;
            break;
        case 1: // Master pose message
            new_master_pose = true;
            break;
        default:
            // Ignore invalid message types
            break;
    }
}
