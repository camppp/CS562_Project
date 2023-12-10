#include <lmdb.h>
#include <memory>
#include <string>
#include <optional>
#include <iostream>

class KeyValueStore {
public:
    KeyValueStore() : env_(nullptr), dbi_(0) {}

    bool open(const std::string& path) {
        int rc = mdb_env_create(&env_);
        if (rc != 0) {
            std::cerr << "Failed to create LMDB environment" << std::endl;
            return false;
        }

        rc = mdb_env_open(env_, path.c_str(), 0, 0664);
        if (rc != 0) {
            std::cerr << "Failed to open LMDB environment" << std::endl;
            mdb_env_close(env_);
            env_ = nullptr;
            return false;
        }

        rc = mdb_txn_begin(env_, nullptr, 0, &txn_);
        if (rc != 0) {
            std::cerr << "Failed to begin transaction" << std::endl;
            mdb_env_close(env_);
            env_ = nullptr;
            return false;
        }

        rc = mdb_dbi_open(txn_, nullptr, 0, &dbi_);
        if (rc != 0) {
            std::cerr << "Failed to open database" << std::endl;
            mdb_txn_abort(txn_);
            mdb_env_close(env_);
            env_ = nullptr;
            return false;
        }

        return true;
    }

    bool put(const std::string& key, const std::string& value) {
        MDB_val k, v;
        k.mv_size = key.size();
        k.mv_data = const_cast<char*>(key.c_str());
        v.mv_size = value.size();
        v.mv_data = const_cast<char*>(value.c_str());

        int rc = mdb_put(txn_, dbi_, &k, &v, 0);
        if (rc != 0) {
            std::cerr << "Failed to put key-value pair" << std::endl;
            return false;
        }

        rc = mdb_txn_commit(txn_);
        if (rc != 0) {
            std::cerr << "Failed to commit transaction" << std::endl;
            return false;
        }

        return true;
    }

    std::optional<std::string> get(const std::string& key) {
        MDB_val k, v;
        k.mv_size = key.size();
        k.mv_data = const_cast<char*>(key.c_str());

        int rc = mdb_txn_begin(env_, nullptr, MDB_RDONLY, &txn_);
        if (rc != 0) {
            std::cerr << "Failed to begin read-only transaction" << std::endl;
            return std::nullopt;
        }

        rc = mdb_get(txn_, dbi_, &k, &v);
        if (rc != 0) {
            mdb_txn_abort(txn_);
            std::cerr << "Failed to get value for key" << std::endl;
            return std::nullopt;
        }

        mdb_txn_commit(txn_);

        return std::string(static_cast<char*>(v.mv_data), v.mv_size);
    }

    ~KeyValueStore() {
        if (env_ != nullptr) {
            mdb_dbi_close(env_, dbi_);
            mdb_env_close(env_);
        }
    }

private:
    MDB_env* env_;
    MDB_dbi dbi_;
    MDB_txn* txn_;
};
