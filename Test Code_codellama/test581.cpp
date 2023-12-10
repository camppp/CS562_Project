void QProcessSize::UpdateBrk() {
    if (memorySize < 1024) {
        brk = 1024;
    } else if (memorySize >= 1024 && memorySize <= 4096) {
        brk = (memorySize / 1024 + 1) * 1024;
    } else {
        brk = memorySize;
    }
}
