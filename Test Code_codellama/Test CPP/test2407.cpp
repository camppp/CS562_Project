class Timeline {
public:
    Timeline() : speed(1.0), state(State::STOPPED) {}

    bool hasStopped() const {
        return state == State::STOPPED;
    }

    void setSpeed(double speed) {
        this->speed = speed;
        if (speed > 0) {
            state = State::PLAYING;
        } else {
            state = State::REVERSED;
        }
    }

private:
    enum class State {
        STOPPED,
        PLAYING,
        REVERSED
    };

    double speed;
    State state;
};
