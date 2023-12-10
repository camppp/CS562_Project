class FileWrapper {
public:
    FileWrapper() : fd(-1) {}
    ~FileWrapper() { close(); }

    void open(const char* filename, int flags) {
        if (fd != -1) {
            close();
        }
        fd = open(filename, flags);
    }

    void close() {
        if (fd != -1) {
            close(fd);
            fd = -1;
        }
    }

    bool isValid() {
        return fd != -1;
    }

private:
    int fd;
};
