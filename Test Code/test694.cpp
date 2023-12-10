#include <nola/internal/avx2.hxx>
#include <nola/internal/avx512.hxx>

void matrix_multiply_simd(const double* A, const double* B, double* C, int m, int n, int p) {
    // Ensure that the matrices are properly aligned for SIMD operations
    constexpr int alignment = 32;
    A = (double*)(((uintptr_t)A + alignment - 1) & ~(alignment - 1));
    B = (double*)(((uintptr_t)B + alignment - 1) & ~(alignment - 1));
    C = (double*)(((uintptr_t)C + alignment - 1) & ~(alignment - 1));

    // Compute the matrix product using AVX2 and AVX512 instructions
    for (int i = 0; i < m; i += 8) {
        for (int j = 0; j < n; j += 16) {
            __m256d a = _mm256_load_pd(A + i * n + j);
            __m256d b = _mm256_load_pd(B + i + j * p);
            __m256d c = _mm256_mul_pd(a, b);
            _mm256_store_pd(C + i * p + j, c);
        }
    }

    // Compute the matrix product using AVX512 instructions
    for (int i = 0; i < m; i += 16) {
        for (int j = 0; j < n; j += 32) {
            __m512d a = _mm512_load_pd(A + i * n + j);
            __m512d b = _mm512_load_pd(B + i + j * p);
            __m512d c = _mm512_mul_pd(a, b);
            _mm512_store_pd(C + i * p + j, c);
        }
    }
}
