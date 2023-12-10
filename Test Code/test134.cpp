case opcode::relative_jump_if_false:
{
  std::int32_t offset = ip.read<std::int32_t>();
  if (!co.stack.empty() && co.stack.top< std::uint8_t >() == 0) {
    ip += offset;  // Update instruction pointer by adding the offset
  } else {
    ip += sizeof(std::int32_t);  // Move to the next instruction as usual
  }
  break;
}
