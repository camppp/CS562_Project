enum class BOM {
    Unknown,
    UTF16LE,
    UTF16BE
};

constexpr std::array<std::array<uint8_t, 2>, 2> BOM_Bytes = {
    {{0xFF, 0xFE}, {0xFE, 0xFF}}
};

BOM detectBOM(const std::vector<uint8_t>& mark) {
    if (mark.size() < 2) {
        return BOM::Unknown;
    }

    for (int i = 0; i < 2; i++) {
        if (::memcmp(mark.data(), BOM_Bytes[i].data(), 2) == 0) {
            return BOM::UTF16LE;
        }
    }

    return BOM::Unknown;
}
