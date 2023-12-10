void CMMX::punpckhbw(const CMMReg& dst, const CMMReg& src)
{
    // Assuming dst and src are valid MMX registers

    // Using inline assembly to perform the punpckhbw operation
    __asm
    {
        movq mm0, src  // Move the source register into mm0
        punpckhbw mm0, dst  // Perform the punpckhbw operation with dst and src, storing the result in mm0
        movq dst, mm0  // Move the result from mm0 back to the destination register
    }
}
