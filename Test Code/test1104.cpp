constexpr bool simd_char_match(char c, const char* char_set) {
    // Load the input character into a SIMD register.
    __m128i input_char = _mm_set1_epi8(c);

    // Load the character set into a SIMD register.
    __m128i char_set_mask = _mm_loadu_si128((const __m128i*)char_set);

    // Compare the input character with each character in the character set.
    __m128i compare_result = _mm_cmpeq_epi8(input_char, char_set_mask);

    // Check if any of the characters in the character set match the input character.
    bool any_match = _mm_movemask_epi8(compare_result) != 0;

    return any_match;
}
