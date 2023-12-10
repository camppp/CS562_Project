void req::__parse_raw() {
    if (this->_raw_len == this->_raw_readed_len) {
        this->_stat = rwg_web::req_stat::req_stat_end;
        return;
    }

    while (this->_raw_readed_len < this->_raw_len) {
        if (this->_buf_pos == this->_buf_avail_size) {
            this->__load();
        }
        // Additional parsing logic here based on the raw data
        // Update _raw_readed_len and _buf_pos accordingly
    }
}
