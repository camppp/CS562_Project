#include <sys/types.h>
#include <sys/select.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>

int isReadyForReading(int fileDescriptor, int timeoutSeconds, int timeoutMicroseconds) {
    fd_set readfds;
    struct timeval timeout;

    FD_ZERO(&readfds);
    FD_SET(fileDescriptor, &readfds);

    timeout.tv_sec = timeoutSeconds;
    timeout.tv_usec = timeoutMicroseconds;

    int ready = select(fileDescriptor + 1, &readfds, NULL, NULL, &timeout);
    if (ready == -1) {
        // Error occurred during select
        return -1;
    } else if (ready == 0) {
        // File descriptor not ready for reading within the specified timeout
        return 0;
    } else {
        // File descriptor is ready for reading
        return 1;
    }
}
