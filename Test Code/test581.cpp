void QProcessSize::UpdateBrk()
{
    if (memorySize < 1024) {
        memorySize = 1024;
    } else if (memorySize <= 4096) {
        memorySize = ((memorySize - 1) / 1024 + 1) * 1024;
    } // else for memorySize > 4096, no change needed
}
