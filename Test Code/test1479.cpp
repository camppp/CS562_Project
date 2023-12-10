void HloReachabilityMap::UpdateReachabilityThroughInstruction(const HloInstruction* instruction) {
  // Retrieve the inputs of the given instruction.
  const std::vector<const HloInstruction*>& inputs = instruction->operands();

  // Update reachability information for each input instruction.
  for (const HloInstruction* input : inputs) {
    result->FastSetReachabilityToUnion(inputs, hlo);
  }
}
