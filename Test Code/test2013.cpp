c
void copy_biases_linear(dType_8u *biases, dType_4u *biases_local_1) {
    // Iterate over the elements of the biases array
    for (int i = 0; i < t_LAYER_i_LENGTH; i++) {
        // Copy the current bias to the local biases array with an offset
        biases_local_1[i + t_LAYER_i_OFFSET] = biases[i];
    }
}
