#include <lmdb.h>
#include <string>
#include <optional>

class KeyValueStore {
public:
    KeyValueStore(const std::string& path) {
        // Open or create an LMDB environment at the specified path
        MDB_env* env;
        MDB_txn* txn;
        MDB_dbi dbi;
        mdb_env_create(&env);
        mdb_env_set_maxdbs(env, 1);
        mdb_env_open(env, path.c_str(), 0, 0664);
        mdb_txn_begin(env, NULL, 0, &txn);
        mdb_dbi_open(txn, NULL, 0, &dbi);
        mdb_txn_commit(txn);
    }

    ~KeyValueStore() {
        // Close the LMDB environment
        MDB_env* env;
        mdb_env_close(env);
    }

    void put(const std::string& key, const std::string& value) {
        // Insert a key-value pair into the LMDB database
        MDB_val key_val, value_val;
        key_val.mv_data = key.data();
        key_val.mv_size = key.size();
        value_val.mv_data = value.data();
        value_val.mv_size = value.size();
        MDB_txn* txn;
        mdb_txn_begin(env, NULL, 0, &txn);
        mdb_put(txn, dbi, &key_val, &value_val, 0);
        mdb_txn_commit(txn);
    }

    std::optional<std::string> get(const std::string& key) {
        // Retrieve the value associated with the given key from the LMDB database
        MDB_val key_val, value_val;
        key_val.mv_data = key.data();
        key_val.mv_size = key.size();
        MDB_txn* txn;
        mdb_txn_begin(env, NULL, 0, &txn);
        mdb_get(txn, dbi, &key_val, &value_val);
        mdb_txn_commit(txn);
        if (value_val.mv_size == 0) {
            return std::nullopt;
        }
        return std::string(value_val.mv_data, value_val.mv_size);
    }

private:
    MDB_env* env;
    MDB_dbi dbi;
};
