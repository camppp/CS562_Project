#include <iostream>
#include <vector>

class ListenSocket {
public:
    virtual ~ListenSocket() = default;
    virtual void Reset() = 0;
    virtual void Prepare() = 0;
    virtual void Start() = 0;
};

class SelectListenStrategy : public ListenStrategy {
public:
    SelectListenStrategy(ListenSocket& m_listenSocket) : m_listenSocket(m_listenSocket) {}
    ~SelectListenStrategy() {
        // Clean up any resources
    }

    void Reset() override {
        // Reset the strategy
    }

    void Prepare() override {
        // Prepare the strategy for listening
    }

    void Start() override {
        // Start the listening process
    }

private:
    ListenSocket& m_listenSocket;
};
