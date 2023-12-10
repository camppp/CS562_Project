NetworkPacket *processPacket(Protocol proto, const uint8_t *data, size_t data_len) {
    if (proto == NLP_IPV4) {
        return IPv4Packet::newPacket(data, data_len);
    } else if (proto == NLP_IPV6) {
        return IPv6Packet::newPacket(data, data_len);
    } else {
        // Handle unsupported protocol
        return nullptr;
    }
}
