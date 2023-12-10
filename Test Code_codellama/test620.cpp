c
void PrintIR(const IRNode* ir) {
    std::cout << "IR Node ID: " << ir->id << std::endl;
    std::cout << "IR Node Type: ";
    PrintType(ir->type);
    std::cout << "IR Node Operator: " << ir->operator_string() << std::endl;
    std::cout << "IR Node Number of Operands: " << ir->get_num_operands() << std::endl;
}
