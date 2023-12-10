uint32_t
MLR_I_DT_TMesh::GetNumPasses(void)
{
    // Check_Object(this);
    if (MLRState::GetMultitextureLightMap() && state.GetMultiTextureMode() != MLRState::MultiTextureOffMode)
    {
        return 2;
    }
    else
    {
        return 1;
    }
}
