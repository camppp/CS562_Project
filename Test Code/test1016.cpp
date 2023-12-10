#include <stdint.h>

void computeInner_stencil2d(uint64_t* bp, uint64_t sub_m, uint64_t sub_n, uint64_t Initial, uint64_t New, uint64_t n_cols) {
    // Your implementation of computeInner_stencil2d goes here
    // This function should perform the required computation based on the given parameters
}

void processTiles(uint64_t M, uint64_t N, uint64_t N_ROWS_TILE_SZ, uint64_t N_COLS_TILE_SZ, uint64_t BlockM_final, uint64_t BlockN, uint64_t* Initial, uint64_t* New, uint64_t n_cols) {
    for (size_t i = 0; i <= M; i += N_ROWS_TILE_SZ) {
        for (size_t j = 0; j <= N; j += N_COLS_TILE_SZ) {
            uint64_t sub_m = (i == M) ? (BlockM_final - i * N_ROWS_TILE_SZ) : ((BlockM_final < N_ROWS_TILE_SZ) ? BlockM_final : N_ROWS_TILE_SZ);
            uint64_t sub_n = (j == N) ? (BlockN - j * N_ROWS_TILE_SZ) : ((BlockN < N_COLS_TILE_SZ) ? BlockN : N_COLS_TILE_SZ);
            uint64_t sub_pos = i * n_cols * N_COLS_TILE_SZ + j * sub_n;
            computeInner_stencil2d(bp + sub_pos, sub_m, sub_n, *Initial, *New, n_cols);
        }
    }
}
