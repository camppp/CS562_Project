#include <immintrin.h>

constexpr bool simd_char_match(char c, const char* char_set, size_t set_size) {
    __m128i input = _mm_set1_epi8(c);  // Broadcast input character to all lanes of the SIMD register
    size_t i = 0;
    for (; i + 16 <= set_size; i += 16) {
        __m128i chunk = _mm_loadu_si128(reinterpret_cast<const __m128i*>(char_set + i));  // Load 16 characters from char_set
        __m128i result = _mm_cmpeq_epi8(input, chunk);  // Compare input with the chunk
        int mask = _mm_movemask_epi8(result);  // Generate a mask of matching positions
        if (mask != 0) {
            return true;  // If any match is found, return true
        }
    }
    for (; i < set_size; ++i) {
        if (char_set[i] == c) {
            return true;  // Linear search for any remaining characters
        }
    }
    return false;  // No match found
}
