bool IsSetCorrespondingAckBit(int byteOffset, int bitOffset)
{
    // Check if the bit at the specified byte and bit offset is set
    return (ackBitField_[byteOffset] & (1 << bitOffset)) != 0;
}
