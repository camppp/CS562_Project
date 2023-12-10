#include <cstdint>
#include <cstring>

enum class BOM {
    Unknown,
    UTF16LE,
    UTF16BE
};

const uint8_t BOM_Bytes[2][2] = {
    { 0xFF, 0xFE },  // UTF16LE BOM
    { 0xFE, 0xFF }   // UTF16BE BOM
};

BOM detectBOM(const uint8_t* mark) {
    if (::memcmp(mark, BOM_Bytes[(int)BOM::UTF16LE], 2) == 0)
        return BOM::UTF16LE;
    else if (::memcmp(mark, BOM_Bytes[(int)BOM::UTF16BE], 2) == 0)
        return BOM::UTF16BE;
    else
        return BOM::Unknown;
}
