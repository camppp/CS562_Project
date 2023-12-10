class WirelessPacket {
public:
    enum class PacketType { /* define packet types here */ };

    // Method to set the delivery stop flags
    void setDeliveryStopFlags(const /* type of flags */ &flags) {
        m_deliveryStopFlags = flags;
    }

    // Method to get the type of the packet
    PacketType type() const {
        return m_type;
    }

private:
    PacketType m_type;
    /* Type of m_deliveryStopFlags */
};
