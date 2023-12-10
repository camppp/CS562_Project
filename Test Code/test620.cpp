void PrintIR(const IRNode* ir) {
    irdump_printf("(%d expression ", ir->id);
    PrintType(ir->type);
    irdump_printf(" %s ", ir->operator_string().c_str());
    for (unsigned i = 0; i < ir->get_num_operands(); i++) {
        // Process and print each operand if needed
    }
    // Add any additional printing or processing if required
}
