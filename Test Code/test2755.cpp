#include <iostream>
#include <cstring>
#include <fcntl.h>
#include <unistd.h>

class FileWrapper {
private:
    int fd_;

public:
    FileWrapper() : fd_(-1) {}

    ~FileWrapper() {
        if (fd_ != -1) {
            close(fd_);
        }
    }

    void open(const char* filename, int flags) {
        if (fd_ != -1) {
            close(fd_);
        }
        fd_ = open(filename, flags);
        if (fd_ == -1) {
            std::cerr << "Failed to open file: " << std::strerror(errno) << std::endl;
        }
    }

    void close() {
        if (fd_ != -1) {
            close(fd_);
            fd_ = -1;
        }
    }

    bool isValid() {
        return fd_ != -1;
    }
};
