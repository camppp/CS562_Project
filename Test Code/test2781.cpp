#include <immintrin.h>

int sumMatrixUsingSIMD(int** matrix, int rows, int cols) {
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        int j = 0;
        __m128i rowSum = _mm_setzero_si128(); // Initialize a SIMD register to store the row sum
        for (; j <= cols - 4; j += 4) {
            __m128i elements = _mm_loadu_si128((__m128i*)&matrix[i][j]); // Load 4 elements from the matrix into a SIMD register
            rowSum = _mm_add_epi32(rowSum, elements); // Add the elements to the row sum using SIMD addition
        }
        int temp[4];
        _mm_storeu_si128((__m128i*)temp, rowSum); // Store the SIMD register into a temporary array
        sum += temp[0] + temp[1] + temp[2] + temp[3]; // Accumulate the row sum
        for (; j < cols; j++) {
            sum += matrix[i][j]; // Add any remaining elements in the row
        }
    }
    return sum;
}
