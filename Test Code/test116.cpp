// Validate the correctness of redo log replay
void validate_redo_log_replay(int64_t log_ts, Memtable* memtable, int64_t lob_start_log_ts_) {
  int ret = OB_SUCCESS;  // Assume OB_SUCCESS is defined as 0
  if (lob_start_log_ts_ == 0) {
    update_max_durable_sql_no(sql_no);
    // TODO: defense inspection
    int64_t redo_log_ts = (lob_start_log_ts_ == 0 ? log_ts : lob_start_log_ts_);
    if (redo_log_ts > memtable->get_freeze_log_ts()) {
      ret = OB_ERR_UNEXPECTED;
      TRANS_LOG(ERROR, "replay should not overflow", K(ret), K(redo_log_ts), K(*memtable));
    }
  }
}
