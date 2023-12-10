void parseMessage(Message *message, int &op, int &device) {
    bool foundOpcode = message->FindInt32("opcode", &op) == B_OK;
    bool foundDevice = message->FindInt32("device", &device) == B_OK;
    
    if (!foundOpcode) {
        // Handle the case where "opcode" key is not found in the message
        // Optionally, set a default value for op
    }
    
    if (!foundDevice) {
        // Handle the case where "device" key is not found in the message
        // Optionally, set a default value for device
    }
}
