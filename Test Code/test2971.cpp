#include <array>
#include <algorithm>

int maxSupportedSIMDVersion(const std::array<uint32_t, 4>& regs) {
    int best = 0;

    // Calculate the supported version for SSE4.2
    int sse4_2 = (regs[0] & 0x0F);
    best = std::max(best, sse4_2);

    // Calculate the supported version for SSE4A (commented out in the original code snippet)
    // int sse4a = (regs[1] >> 6) & 1;
    // best = std::max(best, XSIMD_X86_AMD_SSE4A_VERSION * sse4a);

    // Calculate the supported version for XOP (commented out in the original code snippet)
    // int xop = (regs[1] >> 11) & 1;
    // best = std::max(best, XSIMD_X86_AMD_XOP_VERSION * xop);

    // Calculate the supported version for AVX
    int avx = (regs[3] >> 28) & 1;
    best = std::max(best, avx);

    return best;
}
