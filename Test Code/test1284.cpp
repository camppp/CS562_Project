std::vector<std::vector<PlaintextT>> evaluateCircuit(
    const Circuit& circuit,
    const std::vector<PlaintextT>& inputs,
    const std::vector<Duration>& durations,
    const EvaluationStrategy& evalStrategy
) {
    // Initialize the result vector
    std::vector<std::vector<PlaintextT>> result;

    // Iterate over the inputs and durations
    for (size_t i = 0; i < inputs.size(); i++) {
        // Evaluate the circuit using the current input and duration
        std::vector<PlaintextT> output = evalStrategy(circuit, inputs[i], durations[i]);

        // Add the output to the result vector
        result.push_back(output);
    }

    return result;
}
