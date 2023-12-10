#include <iostream>

// Definition of the Packet class
class Packet {
public:
    // Methods and members of the Packet class
};

// Definition of the EraseIPPayload class
class EraseIPPayload {
public:
    const char *class_name() const { return "EraseIPPayload"; }
    const char *port_count() const { return "PORTS_1_1"; }

    Packet *simple_action(Packet *inputPacket) {
        // Implement the logic to erase the payload of the input packet
        // For example, set the payload to an empty string
        inputPacket->setPayload("");
        return inputPacket;
    }
};
