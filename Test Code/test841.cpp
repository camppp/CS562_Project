int executeAssembly(const string& assemblyCode) {
    // Initialize the registers to 0
    int registers[26] = {0};

    // Split the assembly code into individual commands
    vector<string> commands = split(assemblyCode, '\n');

    // Iterate over the commands and execute them
    for (const string& command : commands) {
        // Split the command into operation and operands
        vector<string> tokens = split(command, ' ');
        string operation = tokens[0];
        vector<string> operands = vector<string>(tokens.begin() + 1, tokens.end());

        // Execute the operation on the operands
        if (operation == "set") {
            registers[operands[0][0] - 'A'] = stoi(operands[1]);
        } else if (operation == "add") {
            registers[operands[0][0] - 'A'] += stoi(operands[1]);
        } else if (operation == "sub") {
            registers[operands[0][0] - 'A'] -= stoi(operands[1]);
        } else if (operation == "mul") {
            registers[operands[0][0] - 'A'] *= stoi(operands[1]);
        } else if (operation == "div") {
            registers[operands[0][0] - 'A'] /= stoi(operands[1]);
        } else if (operation == "mod") {
            registers[operands[0][0] - 'A'] %= stoi(operands[1]);
        }
    }

    // Return the final value in register A
    return registers['A'];
}
