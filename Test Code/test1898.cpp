python
def encodeVariableLength(value):
    byte_stream = bytearray()
    while value >= 0x80:
        byte_stream.append((value & 0x7F) | 0x80)
        value >>= 7
    byte_stream.append(value & 0x7F)
    return byte_stream
