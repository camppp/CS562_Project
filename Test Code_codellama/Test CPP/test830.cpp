c
uint32_t convertEndianness(uint32_t num, enum Endianness endianness) {
    if (endianness == wkbXDR) {
        // Big-endian
        return (num >> 24) | (num << 24);
    } else {
        // Little-endian
        return (num >> 24) | (num << 24);
    }
}
