template <typename ScalingBasis, typename WaveletBasis>
std::pair<SparseVector<ScalingBasis>, SparseVector<WaveletBasis>> ApplyRecur(size_t l, SparseVector<ScalingBasis> Pi_out) {
    // Implement the recursive operation based on the given level and sparse indices
    // ...

    // Construct the output sparse vectors
    SparseVector<ScalingBasis> Pi_scaling = ...;
    SparseVector<WaveletBasis> Pi_wavelet = ...;

    return {Pi_scaling, Pi_wavelet};
}

template <typename ScalingBasis>
std::pair<SparseIndices<ScalingBasis>, SparseIndices<ScalingBasis>> ConstructPiOut(SparseVector<ScalingBasis> Pi_out) {
    // Implement the construction of sparse indices based on the input sparse vector
    // ...

    // Construct the output sparse indices
    SparseIndices<ScalingBasis> Pi_scaling_indices = ...;
    SparseIndices<ScalingBasis> Pi_wavelet_indices = ...;

    return {Pi_scaling_indices, Pi_wavelet_indices};
}
