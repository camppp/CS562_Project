javascript
function simulateCPU(steps, c) {
  for (let i = 0; i < steps; i++) {
    c.cpu_step();
    if (c.registers.pc === 0x017E) {
      return true;
    }
  }
  return false;
}
