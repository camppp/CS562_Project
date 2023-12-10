c
void performTransformationAndStartTimer(struct InputStruct in[], int interface_len) {
    struct OutputStruct api_in[interface_len];
    for (int i428 = 0; i428 < interface_len; i428++) {
        api_in[i428].re = in[i428].f32_2;
    }
    StartAcceleratorTimer();
}
