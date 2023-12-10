bool AckBitField::IsSetCorrespondingAckBit( PacketSN ackSN )
{
    uint32_t difference = 0;
    for ( ; RealtimeSrvHelper::SNGreaterThan(
        latestAckSN_, ackSN++ ); ++difference );

    assert( difference );
    uint32_t byteOffset = ( difference - 1 ) >> 3;
    uint32_t bitOffset = ( difference - 1 ) & 0x7;

    // Complete the implementation by checking if the corresponding acknowledgment bit is set
    // Assuming bitField is a member variable representing the bit field
    if (byteOffset < bitField.size()) {
        uint8_t byte = bitField[byteOffset];
        return (byte & (1 << bitOffset)) != 0;
    } else {
        // Handle out-of-bounds byteOffset
        return false;
    }
}
