#include <iostream>
#include <cstdint>

class I2CController {
private:
    // Private member variables
    int address;
    uint8_t data;
    bool ack;

    // Private methods
    void startTransmission() {
        // Start transmission logic
    }

    void writeByte(uint8_t data) {
        // Write byte logic
    }

    uint8_t readByte(bool ack) {
        // Read byte logic
    }

    void endTransmission() {
        // End transmission logic
    }

public:
    // Constructor
    I2CController(int address) {
        this->address = address;
    }

    // Public methods
    void startTransmission(int address) {
        this->address = address;
        startTransmission();
    }

    void writeByte(uint8_t data) {
        this->data = data;
        writeByte(data);
    }

    uint8_t readByte(bool ack) {
        this->ack = ack;
        return readByte(ack);
    }

    void endTransmission() {
        endTransmission();
    }
};
