#include <iostream>
#include <string>

class Event {
public:
    Event(const std::string& name) : name_(name) {}
    std::string name() const { return name_; }
private:
    std::string name_;
};

class State {
public:
    State(const std::string& name) : name_(name) {}
    std::string name() const { return name_; }
    virtual void entry(const Event& e) = 0;
    virtual void during() = 0;
    virtual void exit(const Event& e) = 0;
    virtual void emit(const Event& e) = 0;
protected:
    std::string name_;
};

class SignalOff : public State {
public:
    SignalOff() : State("Signal light off") {}
    void entry(const Event& e) override {
        std::cout << "Entering state: " << name_ << std::endl;
    }
    void during() override {
        std::cout << "Signal light is off" << std::endl;
    }
    void exit(const Event& e) override {
        emit(Event("signal off"));
    }
    void emit(const Event& e) override {
        std::cout << "Emitting event: " << e.name() << std::endl;
    }
};

class RedSignal : public State {
public:
    RedSignal() : State("Red signal") {}
    void entry(const Event& e) override {
        std::cout << "Entering state: " << name_ << std::endl;
    }
    void during() override {
        std::cout << "Red signal is on" << std::endl;
    }
    void exit(const Event& e) override {
        emit(Event("red signal off"));
    }
    void emit(const Event& e) override {
        std::cout << "Emitting event: " << e.name() << std::endl;
    }
};

class GreenSignal : public State {
public:
    GreenSignal() : State("Green signal") {}
    void entry(const Event& e) override {
        std::cout << "Entering state: " << name_ << std::endl;
    }
    void during() override {
        std::cout << "Green signal is on" << std::endl;
    }
    void exit(const Event& e) override {
        emit(Event("green signal off"));
    }
    void emit(const Event& e) override {
        std::cout << "Emitting event: " << e.name() << std::endl;
    }
};

class TrafficSignal {
public:
    TrafficSignal() : state_(new SignalOff()) {}
    void handleEvent(const Event& event) {
        state_->exit(event);
        if (event.name() == "car detected") {
            delete state_;
            state_ = new RedSignal();
        } else if (event.name() == "red signal off") {
            delete state_;
            state_ = new GreenSignal();
        } else if (event.name() == "green signal off") {
            delete state_;
            state_ = new RedSignal();
        }
        state_->entry(event);
        state_->during();
    }
private:
    State* state_;
};

int main() {
    TrafficSignal trafficSignal;
    trafficSignal.handleEvent(Event("car detected"));
    return 0;
}
