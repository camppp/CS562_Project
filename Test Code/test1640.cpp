ret pixelshuffle3d_channeltospace_aligned(int n, int ic, int oc, int iw, int ow, int ih, int oh, int id, int od, int s, float* x_ptr, float* y_ptr) {
    // Calculate the size of each input and output channel
    int input_channel_size = iw * ih * id;
    int output_channel_size = ow * oh * od;

    // Iterate over the batch elements
    for (int b = 0; b < n; b++) {
        // Iterate over the input channels
        for (int c_in = 0; c_in < ic; c_in++) {
            // Calculate the corresponding output channel index
            int c_out = c_in * s * s * s;

            // Iterate over the input depth
            for (int z = 0; z < id; z++) {
                // Iterate over the input height
                for (int y = 0; y < ih; y++) {
                    // Iterate over the input width
                    for (int x = 0; x < iw; x++) {
                        // Calculate the corresponding output depth, height, and width
                        int z_out = z * s;
                        int y_out = y * s;
                        int x_out = x * s;

                        // Calculate the input and output indices
                        int input_index = b * ic * input_channel_size + c_in * input_channel_size + z * iw * ih + y * iw + x;
                        int output_index = b * oc * output_channel_size + c_out * output_channel_size + z_out * ow * oh + y_out * ow + x_out;

                        // Copy the input element to the corresponding output position
                        y_ptr[output_index] = x_ptr[input_index];
                    }
                }
            }
        }
    }

    // Return success
    return ret_success;
}
