// ListenStrategy class definition
class ListenStrategy {
public:
    virtual ~ListenStrategy() = 0;  // Pure virtual destructor
    virtual void Reset() = 0;        // Pure virtual method
    virtual void Prepare() = 0;      // Pure virtual method
    virtual void Start() = 0;        // Pure virtual method
};

ListenStrategy::~ListenStrategy() {}  // Pure virtual destructor definition

// SelectListenStrategy class definition
class SelectListenStrategy : public ListenStrategy {
private:
    ListenSocket& m_listenSocket;

public:
    SelectListenStrategy(ListenSocket& listenSocket) : m_listenSocket(listenSocket) {}

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
};
