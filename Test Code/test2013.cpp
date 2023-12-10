void copy_biases_linear(dType_8u *biases, dType_4u *biases_local_1)
{
    // Layer 1
    for (int idx = 0; idx < t_LAYER_i_LENGTH; idx++)
    {
        biases_local_1[idx] = biases[idx + t_LAYER_i_OFFSET];
    }
}
