#include <iostream>
#include <mutex>
#include <condition_variable>

enum class Signal { /* ... */ };

class SignalMaster {
public:
    void wait();
    void kill(Signal signal);

private:
    struct State {
        std::mutex mutex;
        std::condition_variable cv;
        bool signalReceived = false;
        Signal receivedSignal;
    };

    State &me() {
        static State state;  // Using static to ensure a single instance
        return state;
    }
};

void SignalMaster::wait() {
    State &state = me();
    std::unique_lock<std::mutex> lock(state.mutex);
    state.cv.wait(lock, [&] { return state.signalReceived; });
    std::cout << "Signal received: " << static_cast<int>(state.receivedSignal) << std::endl;
}

void SignalMaster::kill(Signal signal) {
    State &state = me();
    {
        std::lock_guard<std::mutex> lock(state.mutex);
        state.receivedSignal = signal;
        state.signalReceived = true;
    }
    state.cv.notify_one();
}

int main() {
    SignalMaster signalMaster;
    std::thread t([&] {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        signalMaster.kill(Signal::/* specify a signal */);
    });
    signalMaster.wait();
    t.join();
    return 0;
}
