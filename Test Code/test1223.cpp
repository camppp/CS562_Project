inline CBaseTexture::CBaseTexture(
    CBaseDevice *pDevice,
    DWORD        cLevels,
    D3DPOOL      UserPool,
    D3DFORMAT    UserFormat,
    REF_TYPE     refType)
{
    m_pDevice = pDevice;
    m_cLevels = cLevels;
    m_UserPool = UserPool;
    m_UserFormat = UserFormat;
    m_refType = refType;
}
