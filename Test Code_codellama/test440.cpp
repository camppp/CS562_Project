#include <arm_neon.h>

namespace pxl {
    int32x4_t performFixedPointArithmetic(int32x4_t N, int16x4_t M, int16x4_t P) {
        // Perform fixed-point arithmetic using vqdmlsl_s16 intrinsic
        return vqdmlsl_s16(N, M, P);
    }

    int64x2_t performFixedPointArithmetic(int64x2_t N, int32x2_t M, int32x2_t P) {
        // Perform fixed-point arithmetic using vqdmlsl_s32 intrinsic
        return vqdmlsl_s32(N, M, P);
    }
} // namespace pxl
