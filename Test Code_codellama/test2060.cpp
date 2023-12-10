bool WriteMemory(uintptr_t address, const void* data, size_t length) {
    // Check if the status is not equal to NO_ERROR
    if (status != NO_ERROR) {
        util::LogErrorWithMxStatus(status);
        return false;
    }

    // Perform a debug assertion to ensure that the length matches the number of bytes actually written
    FTL_DCHECK(length == bytes_written);

    // Write the data to the memory address
    bool success = WriteMemory(address, data, length);

    // Log the bytes written at a sufficiently high logging level (>2)
    util::LogBytesWritten(bytes_written);

    return success;
}
