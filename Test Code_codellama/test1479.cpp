void HloReachabilityMap::UpdateReachabilityThroughInstruction(const HloInstruction* instruction) {
    // Get the operands of the instruction
    const std::vector<const HloInstruction*>& operands = instruction->operands();

    // Get the output of the instruction
    const HloInstruction* output = instruction->output();

    // Update the reachability information for the operands
    for (const HloInstruction* operand : operands) {
        // Update the reachability information for the operand
        FastSetReachabilityToUnion(operand, output);
    }

    // Update the reachability information for the output
    FastSetReachabilityToUnion(output, instruction);
}
