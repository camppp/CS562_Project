uint64_t
test_m5_write_file(void *buffer, uint64_t len, uint64_t offset,
                   const char *filename)
{
    if (test_max_buf_size && len > test_max_buf_size)
        len = test_max_buf_size;

    test_total_written += len;

    if (test_host_file_name.empty())
        test_host_file_name = filename;

    // Rest of the implementation for writing the buffer to the file goes here

    return len;  // Return the actual length of the buffer written
}
