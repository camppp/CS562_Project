void GPU_DNFFT_obj::accumulate(const float* M_dev, const DNFFT_Configuration& configuration, float accumulation_factor) {
    // Reset the accumulation state of the transform
    resetAccumulation();

    // Accumulate the input data using the specified configuration and accumulation factor
    accumulate(M_dev, configuration, accumulation_factor);

    // Compute the final result of the transform and store it in f_w_dnfft_gpu
    finalize(f_w_dnfft_gpu);
}
