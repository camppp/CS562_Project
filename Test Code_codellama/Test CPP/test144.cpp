#include <csignal>
#include <iostream>

namespace mimir {
    sig_atomic_t signaled = 0;

    void handleCtrlC(int signal) {
        signaled = 1;
    }

    void performActionOnCtrlC() {
        if (signaled) {
            std::cout << "Ctrl-C signal captured!" << std::endl;
        }
    }
}
