class FileCallbackTest {
private:
    int id_;
    FileIOHelper helper_;
    int max_id_;

public:
    FileCallbackTest(int id, FileIOHelper helper) {
        id_ = id;
        helper_ = helper;
        max_id_ = id;
    }

    virtual void OnFileIOComplete(int bytes_copied) {
        // Handle file I/O completion here
        // ...
    }
};
