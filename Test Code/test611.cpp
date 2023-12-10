void configureLevelDBOptions(const char* dbname, Comparator* cmp, Cache* cache, Env* env, Options* options) {
  // Set the comparator
  options->comparator = cmp;

  // Set the error if exists option
  options->error_if_exists = true;

  // Set the cache
  options->cache = cache;

  // Set the environment
  options->env = env;

  // Set the info log
  options->info_log = new Logger(env, dbname);

  // Set the write buffer size
  options->write_buffer_size = 4 * 1024 * 1024;

  // Set the paranoid checks option
  options->paranoid_checks = true;

  // Set the max open files option
  options->max_open_files = 1000;

  // Set the block size option
  options->block_size = 4 * 1024;

  // Set the block restart interval option
  options->block_restart_interval = 16;

  // Set the max file size option
  options->max_file_size = 2 * 1024 * 1024;

  // Set the compression option
  options->compression = kSnappyCompression;
}
