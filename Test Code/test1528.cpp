# include <sys/select.h>
# include <vector>

class FDSet {
private:
    fd_set set;

public:
    FDSet() {
        FD_ZERO(&set);
    }

    void addFileDescriptor(int fd) {
        FD_SET(fd, &set);
    }

    void removeFileDescriptor(int fd) {
        FD_CLR(fd, &set);
    }

    fd_set* getSet() {
        return &set;
    }
};

class ISelect {
private:
    FDSet fdSet;

public:
    void addFileDescriptor(int fd) {
        fdSet.addFileDescriptor(fd);
    }

    void removeFileDescriptor(int fd) {
        fdSet.removeFileDescriptor(fd);
    }

    int waitForActivity() {
        fd_set* set = fdSet.getSet();
        int maxfd = -1; // Initialize maxfd to -1
        for (int fd = 0; fd < FD_SETSIZE; ++fd) {
            if (FD_ISSET(fd, set)) {
                if (fd > maxfd) {
                    maxfd = fd;
                }
            }
        }

        if (maxfd == -1) {
            return 0; // No file descriptors are set
        }

        struct timeval timeout;
        timeout.tv_sec = 0;
        timeout.tv_usec = 0;

        int ready = select(maxfd + 1, set, NULL, NULL, &timeout);
        return ready;
    }
};
