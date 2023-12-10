void performGraphTransformation(Operation* op, Tensor* inputTensor, Tensor* outputTensor) {
    // Check if the operation is a convolution operation
    if (op->type == "Convolution") {
        // Get the convolution operation's weights and biases
        Weights weights = op->getWeights();
        Biases biases = op->getBiases();

        // Create a new tensor for the convolution output
        Tensor* outputTensor = new Tensor(op->getOutputShape());

        // Perform the convolution operation
        outputTensor->setData(convolution(inputTensor->getData(), weights, biases));

        // Update the graph connections
        op->setOutputTensor(outputTensor);
        outputTensor->setInputTensor(op);
    }
}
