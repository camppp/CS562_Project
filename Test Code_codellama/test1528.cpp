#include <iostream>
#include <vector>
#include <unistd.h>

class FDSet {
private:
    std::vector<int> fds;

public:
    void addFileDescriptor(int fd) {
        fds.push_back(fd);
    }

    void removeFileDescriptor(int fd) {
        fds.erase(std::remove(fds.begin(), fds.end(), fd), fds.end());
    }

    int waitForActivity() {
        fd_set readfds;
        FD_ZERO(&readfds);
        for (int fd : fds) {
            FD_SET(fd, &readfds);
        }
        int maxfd = *std::max_element(fds.begin(), fds.end());
        int ret = select(maxfd + 1, &readfds, NULL, NULL, NULL);
        if (ret > 0) {
            return ret;
        }
        return 0;
    }
};

class ISelect {
private:
    FDSet fdset;

public:
    void addFileDescriptor(int fd) {
        fdset.addFileDescriptor(fd);
    }

    void removeFileDescriptor(int fd) {
        fdset.removeFileDescriptor(fd);
    }

    int waitForActivity() {
        return fdset.waitForActivity();
    }
};
