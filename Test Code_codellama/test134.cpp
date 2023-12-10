case Opcode::relative_jump_if_false:
{
    // Read the 32-bit signed integer offset from the bytecode
    std::int32_t offset = ip.read<std::int32_t>();

    // Check the top value of the stack
    if (co.stack.top() == 0) {
        // Update the instruction pointer by adding the offset
        ip += offset;
    } else {
        // Continue to the next instruction as usual
        ip++;
    }
    break;
}
