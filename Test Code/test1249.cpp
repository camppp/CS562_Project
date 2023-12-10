void performTransformationAndStartTimer(struct InputStruct in[], int interface_len) {
    struct ApiInputStruct api_in[MAX_INTERFACE_LEN];  // Assuming MAX_INTERFACE_LEN is defined appropriately
    for (int i = 0; i < interface_len; i++) {
        api_in[i].re = in[i].f32_2;
    }
    StartAcceleratorTimer();
}
