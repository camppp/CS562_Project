NetworkPacket *p = nullptr;

if (proto == NLP_IPV4) {
    p = IPv4Packet::newPacket(data, data_len);
} else if (proto == NLP_IPV6) {
    p = IPv6Packet::newPacket(data, data_len);
} else {
    // Unknown protocol, drop the packet
    return nullptr;
}

return p;
