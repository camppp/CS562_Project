void SW_CBIR::PoolKernel(float* Cout, float* Pout, int fout, int foutr, int foutc, int ksize, int kstride) {
    for (int f = 0; f < fout; ++f) {
        for (int r = 0; r < foutr; r += kstride) {
            for (int c = 0; c < foutc; c += kstride) {
                float max_val = std::numeric_limits<float>::lowest();
                for (int i = 0; i < ksize; ++i) {
                    for (int j = 0; j < ksize; ++j) {
                        int input_row = r + i;
                        int input_col = c + j;
                        if (input_row < foutr && input_col < foutc) {
                            float val = Pout[f * foutr * foutc + input_row * foutc + input_col];
                            if (val > max_val) {
                                max_val = val;
                            }
                        }
                    }
                }
                Cout[f * (foutr / kstride) * (foutc / kstride) + (r / kstride) * (foutc / kstride) + (c / kstride)] = max_val;
            }
        }
    }
}
