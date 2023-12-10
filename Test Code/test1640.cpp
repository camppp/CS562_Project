int pixelshuffle3d_channeltospace_aligned(int n, int ic, int oc, int iw, int ow, int ih, int oh, int id, int od, int s, float* x_ptr, float* y_ptr) {
    // Calculate the output dimensions
    int ow_aligned = (ow + s - 1) / s;
    int oh_aligned = (oh + s - 1) / s;
    int od_aligned = (od + s - 1) / s;

    // Initialize the output tensor
    for (int i = 0; i < n * oc * ow_aligned * oh_aligned * od_aligned; i++) {
        y_ptr[i] = 0;
    }

    // Perform the pixel shuffle operation
    for (int b = 0; b < n; b++) {
        for (int c = 0; c < ic; c++) {
            for (int w = 0; w < iw; w++) {
                for (int h = 0; h < ih; h++) {
                    for (int d = 0; d < id; d++) {
                        int x_idx = b * ic * iw * ih * id + c * iw * ih * id + w * ih * id + h * id + d;
                        int y_idx = b * oc * ow_aligned * oh_aligned * od_aligned + c * ow_aligned * oh_aligned * od_aligned + w / s * oh_aligned * od_aligned + h / s * od_aligned + d / s;
                        y_ptr[y_idx] += x_ptr[x_idx];
                    }
                }
            }
        }
    }

    // Return the output tensor
    return y_ptr;
}
