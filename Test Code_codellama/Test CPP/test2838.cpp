void SW_CBIR::PoolKernel(float* Cout, float* Pout, int fout, int foutr, int foutc, int ksize, int kstride) {
    // Calculate the number of input feature maps and the number of output feature maps
    int fin = foutr * foutc;
    int fout_total = fout * foutr * foutc;

    // Initialize the output feature maps to zero
    memset(Cout, 0, fout_total * sizeof(float));

    // Loop over the output feature maps
    for (int i = 0; i < fout; i++) {
        // Calculate the starting index of the output feature map
        int start_idx = i * foutr * foutc;

        // Loop over the output feature map rows
        for (int j = 0; j < foutr; j++) {
            // Calculate the starting index of the output feature map row
            int start_idx_row = start_idx + j * foutc;

            // Loop over the output feature map columns
            for (int k = 0; k < foutc; k++) {
                // Calculate the starting index of the output feature map column
                int start_idx_col = start_idx_row + k;

                // Initialize the maximum value to the first element of the input feature map
                float max_val = Pout[start_idx_col];

                // Loop over the input feature map elements in the pooling region
                for (int m = 0; m < ksize; m++) {
                    for (int n = 0; n < ksize; n++) {
                        // Calculate the index of the input feature map element
                        int idx = start_idx_col + m * foutr + n;

                        // Update the maximum value if the input feature map element is greater than the current maximum
                        if (Pout[idx] > max_val) {
                            max_val = Pout[idx];
                        }
                    }
                }

                // Store the maximum value in the output feature map
                Cout[start_idx_col] = max_val;
            }
        }
    }
}
