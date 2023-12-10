#include <leveldb/c.h>

void configureLevelDBOptions(const char* dbname, Comparator* cmp, Cache* cache, Env* env, Options* options) {
    CheckCondition(dbname != NULL);

    options = leveldb_options_create();
    leveldb_options_set_comparator(options, cmp);
    leveldb_options_set_error_if_exists(options, 1);
    leveldb_options_set_cache(options, cache);
    leveldb_options_set_env(options, env);
    leveldb_options_set_info_log(options, NULL);
    leveldb_options_set_write_buffer_size(options, 100000);
    leveldb_options_set_paranoid_checks(options, 1);
    leveldb_options_set_max_open_files(options, 10);
    leveldb_options_set_block_size(options, 1024);
    leveldb_options_set_block_restart_interval(options, 8);
    leveldb_options_set_max_file_size(options, 3 << 20);
    leveldb_options_set_compression(options, leveldb_no_compression);
}
