namespace opencl {

template <typename T>
void transpose_inplace(Array<T>& in, bool conjugate) {
    // Get the dimensions of the input array
    int rows = in.get_rows();
    int cols = in.get_cols();

    // Check if the dimensions are divisible by TILE_DIM
    bool is_divisible = (rows % TILE_DIM == 0) && (cols % TILE_DIM == 0);

    // Call the appropriate kernel function based on the dimensions
    if (is_divisible && conjugate) {
        kernel::transpose_inplace<T, true, true>(in);
    } else if (is_divisible && !conjugate) {
        kernel::transpose_inplace<T, true, false>(in);
    } else {
        kernel::transpose_inplace<T, false, false>(in);
    }
}

} // namespace opencl
