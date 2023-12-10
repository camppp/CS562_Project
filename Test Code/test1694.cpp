(
    uint32_t* pDestination,
    FXMVECTOR V
) noexcept
{
    assert(pDestination);
#if defined(_XM_NO_INTRINSICS_)
    pDestination[0] = V.vector4_u32[0];
    pDestination[1] = V.vector4_u32[1];
    pDestination[2] = V.vector4_u32[2];
    pDestination[3] = V.vector4_u32[3];
    // ... (additional non-intrinsic implementation if needed)
#else
    // Intrinsic implementation
    XMStoreUInt32Array(pDestination, V);
#endif
}
