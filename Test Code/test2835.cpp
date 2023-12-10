c
int calculateTotalScore(const uint8_t* header, size_t length) {
    int score = 0;
    for (size_t i = 0; i < length; i++) {
        if (i == 0x25) {
            uint8_t s_mode = header[i];
            uint8_t s_mapper = s_mode & 0x0f;
            if ((s_mode & 0xf0) == 0x20 && (s_mapper == 0x0 || s_mapper == 0x1 || s_mapper == 0x2 || s_mapper == 0x3 || s_mapper == 0x5 || s_mapper == 0xa)) {
                score += 2;
            }
        }
    }
    return score;
}
