class Counter {
public:
    Counter() : g_counter(0) {}

    void increment() {
        g_counter++;
    }

    void decrement() {
        g_counter--;
    }

    void reset() {
        g_counter = 0;
    }

    int get_value() {
        return g_counter;
    }

private:
    static int g_counter;
};

int Counter::g_counter = 0;
