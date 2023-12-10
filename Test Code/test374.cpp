bitboard rand64_fewbits(int num_bits) {
    bitboard result = 0;
    for (int i = 0; i < num_bits; i++) {
        result |= (rand64() & 1) << i;
    }
    return result;
}
