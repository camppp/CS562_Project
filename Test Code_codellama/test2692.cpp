#include <iostream>
#include <signal.h>

enum class Signal {
    SIGINT,
    SIGTERM,
    SIGQUIT
};

class SignalMaster {
public:
    void wait() {
        // Wait for a signal to be received
        sigset_t mask;
        sigemptyset(&mask);
        sigaddset(&mask, SIGINT);
        sigaddset(&mask, SIGTERM);
        sigaddset(&mask, SIGQUIT);
        sigprocmask(SIG_BLOCK, &mask, NULL);
        sigwait(&mask, NULL);
    }

    void kill(Signal signal) {
        // Send the specified signal to the signal master
        raise(signal);
    }

private:
    struct State {
        // Define necessary state variables
    };

    State &me() {
        static State state;
        return state;
    }
};
