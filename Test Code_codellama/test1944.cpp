c
void parseMessage(Message *message, int &op, int &device) {
    // Check if the "opcode" key exists in the message
    if (message->HasKey("opcode")) {
        // Extract the integer value associated with the "opcode" key
        message->FindInt32("opcode", &op);
    }

    // Check if the "device" key exists in the message
    if (message->HasKey("device")) {
        // Extract the integer value associated with the "device" key
        message->FindInt32("device", &device);
    }
}
