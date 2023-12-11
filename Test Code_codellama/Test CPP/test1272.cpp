size_t ALIGNUP(size_t nSize)
{
    if (IsRunningOnWow64())
    {
        // 64-bit system
        return (nSize + 7) & ~7;
    }
    else
    {
        // 32-bit system
        return (nSize + 3) & ~3;
    }
}
