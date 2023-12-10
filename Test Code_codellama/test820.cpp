class InventorySetupPacket {
public:
    InventorySetupPacket() = default;
    InventorySetupPacket(const InventorySetupPacket& other) {
        // Copy the contents of the other packet
        // into this packet
    }
    InventorySetupPacket(InventorySetupPacket&& other) noexcept {
        // Move the contents of the other packet
        // into this packet
    }
    InventorySetupPacket& operator=(const InventorySetupPacket& other) {
        // Assign the contents of the other packet
        // to this packet
    }
};
