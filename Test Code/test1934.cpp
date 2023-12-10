void punpckhbw(CMMReg dst, CMMReg src) {
    // Load the source register into an MMX register
    __m64 mmSrc = _mm_load_si64(src);

    // Unpack the high-order bytes from the source register
    __m64 mmDst = _mm_unpackhi_pi8(mmSrc, mmSrc);

    // Store the result in the destination register
    _mm_store_si64(dst, mmDst);
}
