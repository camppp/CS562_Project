#include <immintrin.h>

void matrix_multiply_simd(const double* A, const double* B, double* C, int m, int n, int p) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < p; ++j) {
            __m256d sum_avx2 = _mm256_setzero_pd();  // Initialize the sum for AVX2
            __m512d sum_avx512 = _mm512_setzero_pd();  // Initialize the sum for AVX512

            for (int k = 0; k < n; k += 4) {
                __m256d a_avx2 = _mm256_load_pd(&A[i * n + k]);  // Load 4 elements from A using AVX2
                __m256d b_avx2 = _mm256_load_pd(&B[k * p + j]);  // Load 4 elements from B using AVX2
                sum_avx2 = _mm256_fmadd_pd(a_avx2, b_avx2, sum_avx2);  // Perform fused multiply-add using AVX2
            }

            for (int k = 0; k < n; k += 8) {
                __m512d a_avx512 = _mm512_load_pd(&A[i * n + k]);  // Load 8 elements from A using AVX512
                __m512d b_avx512 = _mm512_load_pd(&B[k * p + j]);  // Load 8 elements from B using AVX512
                sum_avx512 = _mm512_fmadd_pd(a_avx512, b_avx512, sum_avx512);  // Perform fused multiply-add using AVX512
            }

            // Store the results back to the output matrix C
            _mm256_store_pd(&C[i * p + j], sum_avx2);  // Store the AVX2 result
            _mm512_store_pd(&C[i * p + j], sum_avx512);  // Store the AVX512 result
        }
    }
}
