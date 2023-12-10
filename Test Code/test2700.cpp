class Timer {
public:
    Timer(int duration, std::function<void()> callback) {
        this->duration = duration;
        this->callback = callback;
    }

    void start() {
        this->startTime = std::chrono::steady_clock::now();
    }

    void stop() {
        this->startTime = std::chrono::steady_clock::now();
    }

    void reset() {
        this->startTime = std::chrono::steady_clock::now();
    }

    void run() {
        if (this->startTime != std::chrono::steady_clock::now()) {
            this->callback();
        }
    }

private:
    int duration;
    std::function<void()> callback;
    std::chrono::steady_clock::time_point startTime;
};
