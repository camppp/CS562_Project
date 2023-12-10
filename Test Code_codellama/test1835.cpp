void handleInputOperation(InterpreterState& state) {
    // Prompt the user for input
    std::cout << "Enter a value: ";
    std::string input;
    std::getline(std::cin, input);

    // Store the input value in the interpreter state
    state.memory[state.programCounter] = input;

    // Increment the program counter to the next instruction
    state.programCounter++;
}
