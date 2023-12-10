void performGraphTransformation(Operation* op, Tensor* inputTensor, Tensor* outputTensor) {
    // Create new operations and tensors as per the transformation logic
    Operation* output_quant = new Operation("output_quant");
    Operation* mul = new Operation("mul");
    Operation* max = new Operation("max");

    Tensor* alpha = new Tensor("alpha");
    Tensor* input_dequant = new Tensor("input_dequant");

    // Modify the names of output_quant and connect it with the existing output tensor
    output_quant->name(std::string(outputTensor->name()->string_view()) + "/output_quant");
    output_quant->input().connect(max->output());

    // Connect the input tensors with the existing operations
    mul->input_b().connect(alpha->output());
    mul->input_a().connect(input_dequant->output());
    max->input_b().connect(mul->output());
    max->input_a().connect(input_dequant->output());

    // Link the input and output tensors with the operations
    link_input_tensor(&input_dequant->input(), inputTensor);
    link_output_tensor(outputTensor, &output_quant->output());
}
