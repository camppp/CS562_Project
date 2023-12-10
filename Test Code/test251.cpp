void handleMessage(int messageType, int data) {
    if (messageType == 0) {
        // Button message
        buttons[0] = (data >> 1) & 1;  // Extract the state of the first button
        buttons[1] = data & 1;          // Extract the state of the second button
        new_buttons_msg = true;         // Set the flag to indicate a new button message
    } else if (messageType == 1) {
        // Master pose message
        new_master_pose = true;  // Set the flag to indicate a new master pose message
    }
    // No action needed for invalid message types
}
