void req::__parse_raw() {
    // Check if the raw data length is equal to the amount of data already read
    if (_raw_len == _raw_readed_len) {
        // Set the status to req_stat_end and return
        _stat = req_stat_end;
        return;
    }

    // While the amount of data already read is less than the length of the raw data
    while (_raw_readed_len < _raw_len) {
        // Parse the raw data
        // ...

        // Increment the amount of data already read
        _raw_readed_len++;

        // Check if the buffer position is equal to the available buffer size
        if (_buf_pos == _buf_avail_size) {
            // Call the private method __load() to load more data into the buffer
            __load();
        }
    }
}
